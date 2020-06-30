#pragma once
#include "Item.h"

class Dagger : public Item
{
public:
	Dagger();
	//att∏¶ 20% ¡ı∞°
	Dagger(Dagger& dagger);
	~Dagger() {};
	void putOn();
	void takeOff();
	Item* copy();
};


