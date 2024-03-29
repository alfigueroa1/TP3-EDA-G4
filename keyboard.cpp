/*******************************************************************************
							 INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include "keyboard.h"
#include "bird.h"
 
 /*********************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 ********************************************************************************/
void handleKeyInputs(bool keyPressed[KEYS], Flock* flock) {
	if (keyPressed[KEY_UP] == true) {
		for (uint i = 0; i < flock->getBirdCount(); i++) {
			(flock->getBird() + i)->updateSpeed(flock->getBird()[i], UP_SPEED);
		}
	}
	if (keyPressed[KEY_DOWN] == true) {

		for (uint i = 0; i < flock->getBirdCount(); i++) {
			(flock->getBird() + i)->updateSpeed(flock->getBird()[i], DOWN_SPEED);
		}
	}
	if (keyPressed[KEY_RIGHT] == true) {
		if (flock->getEyeSight() + JIGGLE_INC <= MAX_SIGHT)
			flock->setEyeSight(flock->getEyeSight() + SIGHT_INC);
		else
			flock->setEyeSight(MAX_SIGHT);
	}
	if (keyPressed[KEY_LEFT] == true) {
		if (flock->getEyeSight() - JIGGLE_INC >= 0)
			flock->setEyeSight(flock->getEyeSight() - SIGHT_INC);
		else
			flock->setEyeSight(0.0);
	}
	if (keyPressed[KEY_1] == true) {
		if (flock->getMode() == MODE2) {
			flock->setMode(MODE1);
			for (uint i = 1; i < flock->getBirdCount(); i++) {
				(flock->getBird() + i)->setSpeed((flock->getBird())->getSpeed());
			}
		}
	}
	if (keyPressed[KEY_2] == true) {
		if (flock->getMode() == MODE1) {
			flock->setMode(MODE2);

			for (uint i = 0; i < flock->getBirdCount(); i++) {
				(flock->getBird() + i)->randSpeed(flock->getBird()[i]);
			}
		}
	}
	if (keyPressed[KEY_W] == true) {
		if(flock->getRandomJiggleLimit()+JIGGLE_INC <= MAX_JIGGLE)
			flock->setRandomJiggleLimit(flock->getRandomJiggleLimit() + JIGGLE_INC);
		else
			flock->setRandomJiggleLimit(MAX_JIGGLE);
	}
	if (keyPressed[KEY_Q] == true) {
		if (flock->getRandomJiggleLimit() - JIGGLE_INC >= 0)
			flock->setRandomJiggleLimit(flock->getRandomJiggleLimit() - JIGGLE_INC);
		else
			flock->setRandomJiggleLimit(0.0);
	}
	return;
}


void handleKeyPress(ALLEGRO_EVENT &ev, bool keyPressed[KEYS], bool down, bool &ok) {
	bool press;
	if (down)
		press = true;
	else
		press = false;
	switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			keyPressed[KEY_UP] = press;		break;
		case ALLEGRO_KEY_DOWN:
			keyPressed[KEY_DOWN] = press;	break;
		case ALLEGRO_KEY_LEFT:
			keyPressed[KEY_LEFT] = press;	break;
		case ALLEGRO_KEY_RIGHT:
			keyPressed[KEY_RIGHT] = press;	break;
		case ALLEGRO_KEY_1:
			keyPressed[KEY_1] = press;		break;
		case ALLEGRO_KEY_2:
			keyPressed[KEY_2] = press;		break;
		case ALLEGRO_KEY_Q:
			keyPressed[KEY_Q] = press;		break;
		case ALLEGRO_KEY_W:
			keyPressed[KEY_W] = press;		break;
		case ALLEGRO_KEY_ESCAPE:
			if(press == false)
				ok = false;
	}
	return;
 }
