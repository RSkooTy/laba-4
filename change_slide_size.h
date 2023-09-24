#ifndef INC_CHANGE_SLIDE_SIZE
#define INC_CHANGE_SLIDE_SIZE
#include "bonus.h"
class change_slide_size :
	public bonus
{
public:
	change_slide_size(pair_t p) :bonus(p) {};
	virtual void drawBonus() override;
	virtual void activate() override;
};

#endif