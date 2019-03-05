#include "LEDController.hpp"



class IdleController: public LEDController {

public:

  IdleController(CRGB* leds, uint16_t num_leds);
  ~IdleController();


};
