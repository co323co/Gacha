#pragma once
#include"Item.h"

class Pickax : public Item
{
public:
	Pickax();
	Pickax(Pickax& pickax);
	~Pickax() {};
	void putOn();
	void takeOff();
	Item* copy();
};