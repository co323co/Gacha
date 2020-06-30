#pragma once
#include "Item.h"

class Bow : public Item
{
public:
	Bow();
	Bow(Bow& bow);
	~Bow() {};
	//att를 2배 증가
	void putOn();
	void takeOff();
	Item* copy();
};
