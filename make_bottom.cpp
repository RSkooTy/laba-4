#include "make_bottom.h"
#include "ball.h"

void make_bottom::activate() {
	ball::makeBottom();
}

void make_bottom::drawBonus() {
	drawNGon(6);
}