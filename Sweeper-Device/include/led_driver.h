#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        13
#define NUMPIXELS   8


//predefined colors
#define RED 50,0,0

#define PURPLE 26,10,50

#define ORANGE 50,26,0
#define YELLOW 50,50,0
#define L_GREEN 25,50,0
#define GREEN 0,50,0
#define TURQ 0,25,25
#define BLUE 0,0,50


#define BLINK_DELAY 500
#define FAST_BLINK 250

//prototypes

void led_init(void);
void blink_color(uint8_t,uint8_t,uint8_t,int);
void static_color(uint8_t,uint8_t,uint8_t);