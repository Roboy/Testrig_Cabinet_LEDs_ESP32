
#include "main.hpp"
#include "patterns.hpp"
#include "LEDController.hpp"
#include "LEDControllers/IdleController.hpp"

// FASTLED_USING_NAMESPACE


#define DATA_PIN_L    32
#define CLK_PIN_L     21
#define DATA_PIN_R    25
#define CLK_PIN_R     22
#define LED_TYPE    APA102
#define COLOR_ORDER RGB
#define NUM_LEDS    86

#define BRIGHTNESS         150
#define FRAMES_PER_SECOND  120


CRGB ledsL[NUM_LEDS];
CRGB ledsR[NUM_LEDS];


void setup() {
  delay(3000); // 3 second delay for recovery

  WiFi.persistent(false);         //Permanentes Schreiben im Flash abschalten http://www.forum-raspberrypi.de/Thread-esp8266-achtung-flash-speicher-schreibzugriff-bei-jedem-aufruf-von-u-a-wifi-begin
  WiFi.mode(WIFI_STA);

  #ifdef WIFI_IP
  if (!WiFi.config(WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET, WIFI_DNS_PRIMARY, WIFI_DNS_SECONDARY)) {
    Serial.println("STA Failed to configure");
  }
  #endif

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);


  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN_L,CLK_PIN_L>(ledsL, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE,DATA_PIN_R,CLK_PIN_R>(ledsR, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}


// List of patterns to cycle through.  Each is defined as a separate function below.
//typedef void (*SimplePatternList[])();
//SimplePatternList gPatterns = { rainbow, sinelon, juggle, bpm };

//uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
//uint8_t gHue = 0; // rotating "base color" used by many of the patterns

LEDController idleController = IdleController(ledsL, NUM_LEDS);


void loop()
{
  // Call the current pattern function once, updating the 'leds' array
//  gPatterns[gCurrentPatternNumber]();

  // send the 'leds' array out to the actual LED strip
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND);

  // do some periodic updates
//  EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
//  EVERY_N_SECONDS( 10 ) { nextPattern(); } // change patterns periodically
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
//  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}
