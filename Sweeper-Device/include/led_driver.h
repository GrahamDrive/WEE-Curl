#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        13
#define NUMPIXELS   8


//predefined colors
#define RED 25,0,0
#define BLUE 0,0,25
#define GREEN 0,25,0
#define ORANGE 25,13,0
#define YELLOW 25,25,0
#define TEAL 0,25,25
#define PINK 25,0,25

#define BLINK_DELAY 500

//prototypes

void led_init(void);
void blink_color(uint8_t,uint8_t,uint8_t,int);
void static_color(uint8_t,uint8_t,uint8_t);