#include "game_object.h"
#include <GL/freeglut.h>

pair_t game_object:: windowSize;
int game_object::mainTime;
int game_object::delay;
int game_object::radius;

void game_object::move() {
	pos.x += speed.x;
	pos.y += speed.y;
}

int game_object::create_random(int n) {
	return (rand() + time(NULL)) % n;
}

void game_object::drawNGon(int n) {
	double pi = 2 * acos(0.0);
	glBegin(GL_POLYGON); 
	for (int i = 0; i < n; ++i)
		glVertex2f(pos.x + radius * cos(2 * pi / n * i), pos.y + radius * sin(2 * pi / n * i));
	glEnd();
}