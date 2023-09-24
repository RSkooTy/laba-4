#ifndef INC_STICKING_H
#define INC_STICKING_H
#include "bonus.h"
class sticking :
    public bonus
{
public:
	sticking(pair_t p) : bonus(p) {};
	virtual void drawBonus() override;
	virtual void activate() override;
};
#endif
