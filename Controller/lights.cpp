#include "lights.h"

#include "hardware.h"
#include "log.h"

#include <Adafruit_NeoPixel.h>
#include <Adafruit_IS31FL3741.h>

Adafruit_NeoPixel shieldLights(37, PIN_WS2812_B, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel cannonLights(4, PIN_WS2812_A, NEO_GRB + NEO_KHZ800);

#define strip shieldLights

uint32_t Wheel(byte WheelPos);
void theaterChaseRainbow(uint8_t wait);
void rainbow(uint8_t wait);
void theaterChase(uint32_t color, int wait);
void colorWipe(uint32_t color, int wait);

unsigned long pixelPrevious = 0;        // Previous Pixel Millis
unsigned long patternPrevious = 0;      // Previous Pattern Millis
int           patternCurrent = 0;       // Current Pattern Number
int           patternInterval = 5000;   // Pattern Interval (ms)
int           pixelInterval = 50;       // Pixel Interval (ms)
int           pixelQueue = 0;           // Pattern Pixel Queue
int           pixelCycle = 0;           // Pattern Pixel Cycle
uint16_t      pixelCurrent = 0;         // Pattern Current Pixel Number
uint16_t      pixelNumber = 37;  // Total Number of Pixels



Adafruit_IS31FL3741_QT matrix;
// If colors appear wrong on matrix, try invoking constructor like so:
// Adafruit_IS31FL3741_QT matrix(IS3741_RBG);

char text[] = "CALLIDUS ROBOT";   // A message to scroll
int text_x = matrix.width(); // Initial text position = off right edge
int text_y = 1;
int text_min;                // Pos. where text resets (calc'd later)

void CallidusLights::setup() {
  Log::info(F("Initializing lights subsystem..."));

  // WS2812 channel A output
  digitalWrite(PIN_WS2812_A, LOW);
  pinMode(PIN_WS2812_A, OUTPUT);
  // WS2812 channel B output
  digitalWrite(PIN_WS2812_B, LOW);
  pinMode(PIN_WS2812_B, OUTPUT);


  shieldLights.begin();
  cannonLights.begin();

  for (int i = 0; i < 4; i++)
    cannonLights.setPixelColor(i, cannonLights.Color(255, 255, 255));

  shieldLights.show();
  cannonLights.show();
  shieldLights.setBrightness(100); // max 255
  cannonLights.setBrightness(100);



  if (!matrix.begin(IS3741_ADDR_DEFAULT, &I2C_PORT)) {
    Log::error(F("IS41 not found"));
  }
  // Set brightness to max and bring controller out of shutdown state
  matrix.setLEDscaling(0xFF);
  matrix.setGlobalCurrent(0xFF);
  Serial.print("Global current set to: ");
  Serial.println(matrix.getGlobalCurrent());

  matrix.fill(0);
  matrix.enable(true); // bring out of shutdown
  matrix.setRotation(0);
  matrix.setTextWrap(false);

  // Get text dimensions to determine X coord where scrolling resets
  uint16_t w, h;
  int16_t ignore;
  matrix.getTextBounds(text, 0, 0, &ignore, &ignore, &w, &h);
  text_min = -w; // Off left edge this many pixels
}

void CallidusLights::setPattern(int pattern) {
  patternCurrent = pattern & 7;
}

void CallidusLights::update() {
  unsigned long currentMillis = millis();                     //  Update current time
  if((currentMillis - patternPrevious) >= /*patternInterval*/ 25) {  //  Check for expired time
    patternPrevious = currentMillis;
    //patternCurrent++;                                         //  Advance to next pattern
    //if(patternCurrent >= 7)
    //  patternCurrent = 0;

    matrix.setCursor(text_x, text_y);
    for (int i = 0; i < (int)strlen(text); i++) {
      // set the color thru the rainbow
      uint32_t color888 = matrix.ColorHSV(map(patternCurrent, 0, 7, 0, 65535), map(i, 0, strlen(text) - 1, 64, 255));
      uint16_t color565 = matrix.color565(color888);
      matrix.setTextColor(color565, 0); // backound is '0' to erase previous text!
      matrix.print(text[i]); // write the letter
    }

    if (--text_x < text_min) {
      text_x = matrix.width();
    }
  }
  
  if(currentMillis - pixelPrevious >= pixelInterval) {        //  Check for expired time
    pixelPrevious = currentMillis;                            //  Run current frame
    switch (patternCurrent) {
      case 7:
        theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
        break;
      case 6:
        rainbow(10); // Flowing rainbow cycle along the whole strip
        break;     
      case 5:
        theaterChase(strip.Color(0, 0, 127), 50); // Blue
        break;
      case 4:
        theaterChase(strip.Color(127, 0, 0), 50); // Red
        break;
      case 3:
        theaterChase(strip.Color(127, 127, 127), 50); // White
        break;
      case 2:
        colorWipe(strip.Color(0, 0, 255), 50); // Blue
        break;
      case 1:
        colorWipe(strip.Color(0, 255, 0), 50); // Green
        break;        
      default:
        colorWipe(strip.Color(255, 0, 0), 50); // Red
        break;
    }
  }
}

// Some functions of our own for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  if(pixelInterval != wait)
    pixelInterval = wait;                   //  Update delay time
  strip.setPixelColor(pixelCurrent, color); //  Set pixel's color (in RAM)
  strip.show();                             //  Update strip to match
  pixelCurrent++;                           //  Advance current pixel
  if(pixelCurrent >= pixelNumber)           //  Loop the pattern from the first LED
    pixelCurrent = 0;
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color, int wait) {
  if(pixelInterval != wait)
    pixelInterval = wait;                   //  Update delay time
  for(int i = 0; i < pixelNumber; i++) {
    strip.setPixelColor(i + pixelQueue, color); //  Set pixel's color (in RAM)
  }
  strip.show();                             //  Update strip to match
  for(int i=0; i < pixelNumber; i+=3) {
    strip.setPixelColor(i + pixelQueue, strip.Color(0, 0, 0)); //  Set pixel's color (in RAM)
  }
  pixelQueue++;                             //  Advance current pixel
  if(pixelQueue >= 3)
    pixelQueue = 0;                         //  Loop the pattern from the first LED
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(uint8_t wait) {
  if(pixelInterval != wait)
    pixelInterval = wait;                   
  for(uint16_t i=0; i < pixelNumber; i++) {
    strip.setPixelColor(i, Wheel((i + pixelCycle) & 255)); //  Update delay time  
  }
  strip.show();                             //  Update strip to match
  pixelCycle++;                             //  Advance current cycle
  if(pixelCycle >= 256)
    pixelCycle = 0;                         //  Loop the cycle back to the begining
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  if(pixelInterval != wait)
    pixelInterval = wait;                   //  Update delay time  
  for(int i=0; i < pixelNumber; i+=3) {
    strip.setPixelColor(i + pixelQueue, Wheel((i + pixelCycle) % 255)); //  Update delay time  
  }
  strip.show();
  for(int i=0; i < pixelNumber; i+=3) {
    strip.setPixelColor(i + pixelQueue, strip.Color(0, 0, 0)); //  Update delay time  
  }      
  pixelQueue++;                           //  Advance current queue  
  pixelCycle++;                           //  Advance current cycle
  if(pixelQueue >= 3)
    pixelQueue = 0;                       //  Loop
  if(pixelCycle >= 256)
    pixelCycle = 0;                       //  Loop
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
