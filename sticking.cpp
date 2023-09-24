#include "sticking.h"
#include "slide.h"

void sticking::drawBonus() {
	drawNGon(8);
}
void sticking::activate() {
	slide::mainSlide->activateSticking();
}