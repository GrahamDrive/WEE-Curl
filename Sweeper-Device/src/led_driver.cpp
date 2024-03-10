#include "led_driver.h"

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void led_init(){

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
#endif
    pixels.begin();
}


void blink_color(uint8_t r,uint8_t g,uint8_t b, int n){
    /*
    INPUTS: uint8_t - represents the color code for the leds
            int - number of times you want to blink the led
    */
    for(int i = 0; i < n; i ++){
        for (int i = 0; i < NUMPIXELS; i++)
        {
            pixels.setPixelColor(i, pixels.Color(r, g, b));
        }
        pixels.show();
        delay(BLINK_DELAY);
        pixels.clear();
        pixels.show();
        delay(BLINK_DELAY);
    }

}

void static_color(uint8_t r,uint8_t g,uint8_t b){
    /*
    INPUTS: uint8_t - represents the color code
    NOTE: you can read in 0 for all three codes to turn it off
    */
    for (int i = 0; i < NUMPIXELS; i++)
        {
            pixels.setPixelColor(i, pixels.Color(r, g, b));
        }
    pixels.show();
}