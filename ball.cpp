#include "ball.h"
#include "slide.h"
#include "game.h"
#include <GL/freeglut.h>

std::set<ball*> ball::balls;
int ball::speed_changing_time;
bool ball::bottom;
double ball::normal_speed;
pair_t emp = { -1, -1 };

void ball::initBonuses() {
    speed_changing_time = INT_MIN;
    bottom = false;
}

void ball::makeBottom() {
    bottom = true;
}

void ball::drawAllBalls() {
    for (auto u : balls) {
        glColor3f(1.0f, 1.0f, 1.0f);
        u->drawBall();
    }
}

void ball::drawBall() {
    drawNGon(30);

    if (bottom) {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0, 0);
        glVertex2f(0, 10);
        glVertex2f(600, 10);
        glVertex2f(600, 0);
        glEnd();
    }
}

void ball::changeSpeed() {
    speed_changing_time = mainTime;
}

bool ball::isAlife() {
    if (pos.y < 0) return false;
    return true;
}

void ball::move() {
    if (sticking) {
        pair_t t = slide::mainSlide->getPos();
        pair_t s = slide::mainSlide->getSize();
        pos.x = t.x;
        pos.y = t.y + s.y + radius;
        return;
    }

    if (pos.y + radius >= windowSize.y) {
        speed.y *= -1;
    }

    if (mainTime - speed_changing_time <= delay) {
        pos.x += speed.x * 2;
        pos.y += speed.y * 2;
    }
    else {
        pos.x += speed.x;
        pos.y += speed.y;
    }

    if (pos.x - radius <= 0 || pos.x + radius >= windowSize.x) {
        speed.x *= -1;
    }

    if (bottom && pos.y - radius <= 0) {
        speed.y *= -1;
        bottom = false;
    }
}

pair_t ball::getSize() {
    return { radius * 2, radius * 2 };
}

void ball::stick() {
    sticking = true;
}

void ball::notstick() {
    sticking = false;
}

void ball::pushOff(game_object* v) {
    pair_t t = game::touch(this, v);
    double rnd_offset = (game_object::create_random(3) - 1) * 0.01;

    if (t.x < t.y) {
        double alpha = (this->getPos().x - v->getPos().x) * 120 / v->getSize().x;
        double sy = normal_speed * cos(alpha) + rnd_offset;
        double sx = (-1) * normal_speed * sin(alpha) + rnd_offset;
        this->speed = { sx, sy };

        if (v == slide::mainSlide) {
            this->speed = { this->speed.x, -this->speed.y };
        }
    }
    else {
        double alpha = (this->getPos().y - v->getPos().y) * 120 / v->getSize().y;
        double sy = normal_speed * sin(alpha) + rnd_offset;
        double sx = (-1) * normal_speed * cos(alpha) + rnd_offset;
        this->speed = { sx, sy };

        if (v == slide::mainSlide) {
            this->speed = { -this->speed.x, this->speed.y };
        }
    }
    while (game::touch(this, v) != emp) {
        this->move();
    }
}
