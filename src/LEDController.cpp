#include "LEDController.hpp"

LEDController::LEDController(CRGB* leds, uint16_t num_leds){
  this->leds = leds;
  this->num_leds = num_leds;
}

LEDController::~LEDController(){}
