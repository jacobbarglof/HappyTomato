#ifndef GLOBALS_H
#define GLOBALS_H

#include "hardware/DisplayManager.h"
#include "hardware/InputManager.h"
#include "hardware/Buzzer.h"
#include "ui/TomatoSprite.h"

// Declare global instances used across features
extern DisplayManager display;
extern InputManager input;
extern Buzzer buzzer;
extern TomatoSprite sprite;

#endif
