#pragma once
#include"Item.h"

class Gold : public Item
{
public:
	Gold();
	Gold(int amount);
	Gold(Gold& gold);
	~Gold() {};
	Item* copy();
};