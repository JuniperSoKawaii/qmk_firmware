use std::env;
use std::path::PathBuf;

fn main() {
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());

    // parse env vars passed by qmk
    let qmk_base = env::var("QMK_BASE_DIR").expect("did not specify QMK_BASE_DIR env var");
    let keymap_output = env::var("KEYMAP_OUTPUT").expect("did not specify KEYMAP_OUTPUT env var");
    let qmk_keyboard_h =
        env::var("QMK_KEYBOARD_H").expect("did not specify QMK_KEYBOARD_H env var");
    let rust_qmk_headers =
        std::env::var("RUST_QMK_HEADERS").expect("did not specify RUST_QMK_HEADERS env var");

    // read preprocessor flags generated by qmk
    let clang_flags = std::fs::read_to_string(
        PathBuf::from(&qmk_base)
            .join(keymap_output)
            .join("preprocessor.txt"),
    )
    .expect("unable to read preprocessor.txt flags from qmk");

    // specify common bindgen headers
    let mut headers = vec![
        format!("{}", qmk_keyboard_h.split("/").next().unwrap()),
        "config.h".to_string(),
        "quantum.h".to_string(),
    ];

    // allow users to specify additional bindgen headers
    if !rust_qmk_headers.trim().is_empty() {
        headers.extend(rust_qmk_headers.trim().split(" ").map(|s| s.to_string()))
    }

    // create wrapper.h to pass to bindgen
    std::fs::write(
        out_path.join("wrapper.h"),
        headers
            .into_iter()
            .map(|h| format!("#include \"{}\"", h))
            .collect::<Vec<_>>()
            .join("\n"),
    )
    .unwrap();

    // create the bindings
    let bindings = bindgen::Builder::default()
        .header(out_path.join("wrapper.h").to_str().unwrap())
        .use_core()
        .layout_tests(false)
        .ctypes_prefix("ctypes")
        .default_enum_style(bindgen::EnumVariation::ModuleConsts)
        .blacklist_item("FP_INFINITE")
        .blacklist_item("FP_NAN")
        .blacklist_item("FP_NORMAL")
        .blacklist_item("FP_SUBNORMAL")
        .blacklist_item("FP_ZERO")
        .blacklist_function("__.*")
        .clang_arg(format!("-working-directory={}", qmk_base))
        .clang_args(clang_flags.trim().split(" "))
        .clang_arg("-Wno-invalid-pp-token")
        .generate()
        .expect("Unable to generate bindings");

    // Write the bindings to the $OUT_DIR/bindings.rs file.
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
