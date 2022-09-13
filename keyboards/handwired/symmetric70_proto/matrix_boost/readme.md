# Debug version matrix.c(0.17.0), matrix_extension_74hc157.c and matrix_read_cols_on_row.c

This directory is provided for testing and performance evaluation of [`users/mtei/matrix_read_cols_on_row.c`](../../../../users/mtei/readme_matrix_read_cols_on_row.md)  using symmetric70_proto.

The matrix.c in this directory is 0.17.0:quantum/matrix.c with the following additions:

* Added the MATRIX_DEBUG_SCAN_{START/END} macro to measure the execution time of matrix_scan().
* Added the MATRIX_DEBUG_DELAY_{START/END} macro to measure delay time.

The matrix_extension_74hc157.c in this directory provides `matrix_read_cols_on_row()` that adds support for 74hc157 used in the symmetric70_proto/promicro hardware.

## Current performance

### Without fast `matrix_read_cols_on_rows() in users/mtei/`

* Measurement with QMK 0.17.0

| MCU               | execution time of `matrix_scan()` | matrix scan rate |
|-------------------|---------------|----------------|
| Pro Micro (16MHz) | 588.7 us      | 1539 scans/sec (649.9us) |
| Proton C (72MHz)  | TBD us     | TBD scans/sec |

### With fast `matrix_read_cols_on_rows() in users/mtei/`

* Measurement with QMK 0.17.0

| MCU               | execution time of `matrix_scan()` | matrix scan rate |
|-------------------|---------------|----------------|
| Pro Micro (16MHz) | 92.25 us     | 6536 scans/sec (153us) |
| Proton C (72MHz)  | TBD us     | TBD scans/sec |

## Configuration

`users/mtei/matrix_read_cols_on_row.c` requires its own non-standard matrix configuration.
[see Configuration in users/mtei/readme_matrix_read_cols_on_row.md](../../../../users/mtei/readme_matrix_read_cols_on_row.md#configuration)

## Easy way to configure

[see How to use `matrix_read_cols_on_rows.c` in users/mtei/readme_matrix_read_cols_on_row.md](../../../../users/mtei/readme_matrix_read_cols_on_row.md#how-to-use-matrix_read_cols_on_rowsc-with-an-existing-keyboard)

## Compile

* Set MATRIX_IO_DELAY value
  * `make MTEST=mdelay0 handwired/symmetric70_proto/promicro/boost:default:flash`
  * `make MTEST=mdelay=1 handwired/symmetric70_proto/promicro/boost:default:flash`
  * `make MTEST=mdelay=30 handwired/symmetric70_proto/promicro/boost:default:flash`
* Measure the execution time of matrix_scan()
  * `make MTEST=matrix_debug_scan[,<other options>..] handwired/symmetric70_proto/promicro/boost:default:flash`
* Measure delay time.
  * `make MTEST=matrix_debug_delay[,<other options>..] handwired/symmetric70_proto/promicro/boost:default:flash`
* Measure the execution time of matrix_scan() and delay time.
  * `make MTEST=matrix_debug_delay,matrix_debug_scan[,<other options>..] handwired/symmetric70_proto/promicro/boost:default:flash`
* Change the behavior of delay
  * `make MTEST=matrix_debug_delay,mdelay_type=adaptive handwired/symmetric70_proto/promicro/boost:default:flash`
  * `make MTEST=matrix_debug_delay,mdelay_type=time,mdelay=30 handwired/symmetric70_proto/promicro/boost:default:flash`
  * `make MTEST=matrix_debug_delay,mdelay_type=ipullup handwired/symmetric70_proto/promicro/boost:default:flash`
* Don't use fast `matrix_read_cols_on_rows()`
  * `make CANCEL_BOOST=yes MTEST=[<other options>...] handwired/symmetric70_proto/promicro/boost:default:flash`

## Measurement result
### Pro Micro (ATmega32u4 16Mhz)
#### Default setting (without fast `matrix_read_cols_on_rows()`)
 - `make CANCEL_BOOST=yes MTEST=matrix_debug_scan,matrix_debug_delay handwired/symmetric70_proto/promicro/boost:default:flash`

<img width="80%" alt="sym70_normal_promicro" src="https://user-images.githubusercontent.com/2170248/179529297-80b0a96f-0f7b-4822-811b-4a13055088af.png">

#### Default setting (with fast `matrix_read_cols_on_rows()`)
 - `make MTEST=matrix_debug_scan,matrix_debug_delay handwired/symmetric70_proto/promicro/boost:default:flash`

<img width="80%" alt="sym70_fastread_promicro" src="https://user-images.githubusercontent.com/2170248/179529392-8a5693da-b8a7-4368-bf74-ffa58556ba1e.png">

### Proton C (STM32F303 72MHz)
#### Default setting (without fast `matrix_read_cols_on_rows()`)
 - `make CANCEL_BOOST=yes MTEST=matrix_debug_scan,matrix_debug_delay handwired/symmetric70_proto/proton_c/boost:default:flash`

TBD

#### Default setting (with fast `matrix_read_cols_on_rows()`)
 - `make MTEST=matrix_debug_scan,matrix_debug_delay handwired/symmetric70_proto/proton_c/boost:default:flash`

TBD

##### Connect a 500pF capacitor between C1 line and GND, Press R0C1, R1C1, R2C1,  R3C1,  R4C1 keys

TBD

##### Connect a 1000pF capacitor between C1 line and GND, Press R0C1, R1C1, R2C1,  R3C1,  R4C1 keys

TBD
