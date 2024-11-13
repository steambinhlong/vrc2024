#include "Arduino.h"

typedef struct Gamepad
{
  char* MAC_ADDRESS;


} Gamepad;

void gamepad_init(Gamepad *gamepad, String MAC_ADDRESS);