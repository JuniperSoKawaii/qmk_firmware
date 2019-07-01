#include "ps2.h"
#include "ps2_usb.h"


void led_set_kb(uint8_t usb_led)
{
  uint8_t ps2_led = 0;
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    ps2_led |= (1 << PS2_LED_SCROLL_LOCK);
  }
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    ps2_led |= (1 << PS2_LED_NUM_LOCK);
  }
  if (IS_LED_ON(USB_LED_CAPS_LOCK)) {
    ps2_led |= (1 << PS2_LED_CAPS_LOCK);
  }
  ps2_host_set_led(ps2_led);
  led_set_user(usb_led);
}
