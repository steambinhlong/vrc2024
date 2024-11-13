#include "gamepad.h"
#include "string.h"
#include <PS4Controller.h>

void gamepad_init(Gamepad *gamepad, char *MAC_ADDRESS)
{
    strcpy(gamepad -> MAC_ADDRESS, MAC_ADDRESS);

    PS4.begin(gamepad -> MAC_ADDRESS);
}