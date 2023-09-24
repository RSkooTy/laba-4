#include "block.h"
#include <GL/freeglut.h>
#include "add_ball.h"
#include "change_ball_speed.h"
#include "change_slide_size.h"
#include "sticking.h"
#include "make_bottom.h"

std::set <block*> block::blocks;
pair_t block::size;

void block::setSize(pair_t s) {
	size = s;
}

bool block::isAlife() {
    return (hp > 0);
}

void block::drawBlock() {

	float greenComponent = 1.0f - static_cast<float>(hp) / 3.0f;
	float redComponent = static_cast<float>(hp) / 3.0f;

	if (greenComponent < 0.0f) greenComponent = 0.0f;
	if (redComponent > 1.0f) redComponent = 1.0f;

	glBegin(GL_QUADS);
	glColor3f(redComponent, greenComponent, 0.0f); 
	glVertex2f(pos.x - size.x / 2, pos.y - size.y / 2);
	glVertex2f(pos.x - size.x / 2, pos.y + size.y / 2);
	glVertex2f(pos.x + size.x / 2, pos.y + size.y / 2);
	glVertex2f(pos.x + size.x / 2, pos.y - size.y / 2);
	glEnd();
}

void block::drawAllBlocks() {
	for (auto u : blocks) {
		u->drawBlock();
	}
}

void block::touch() {
	if (hp != absolut)
		hp--;
}

void block::create_bonus() {
	int var = create_random(5);
	bonus* p;
	switch (var) {
	case 0:
		p = new add_ball(pos);
		break;
	case 1:
		p = new change_ball_speed(pos);
		break;
	case 2:
		p = new change_slide_size(pos);
		break;
	case 3:
		p = new make_bottom(pos);
		break;
	case 4:
		p = new sticking(pos);
		break;
	}
}