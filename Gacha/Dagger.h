#pragma once
#include "Item.h"

class Dagger : public Item
{
public:
	Dagger();
	//att�� 20% ����
	Dagger(Dagger& dagger);
	~Dagger() {};
	void putOn();
	void takeOff();
	Item* copy();
};


