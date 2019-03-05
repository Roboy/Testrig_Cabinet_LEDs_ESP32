#ifndef IDLE_CONTROLLER_HPP
#define IDLE_CONTROLLER_HPP

#include <FastLED.h>

class LEDController {

public:

  LEDController(CRGB* leds, uint16_t num_leds);
  ~LEDController();


protected:
  CRGB* leds;
  uint16_t num_leds;

};

#endif
