#include "change_slide_size.h"
#include "slide.h"
void change_slide_size::drawBonus() {
	drawNGon(5);
}
void change_slide_size::activate() {
	slide::mainSlide->changeSize();
}