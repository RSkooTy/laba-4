#include "change_ball_speed.h"
#include "ball.h"

void change_ball_speed::drawBonus() {
	drawNGon(4);
}
void change_ball_speed::activate() {
	ball::changeSpeed();
}