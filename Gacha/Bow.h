#pragma once
#include "Item.h"

class Bow : public Item
{
public:
	Bow();
	Bow(Bow& bow);
	~Bow() {};
	//att�� 2�� ����
	void putOn();
	void takeOff();
	Item* copy();
};
