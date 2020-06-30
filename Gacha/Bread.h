#pragma once
#include "Item.h"

class Bread : public Item
{
	int healingAmount = 5;
public:
	Bread();
	Bread(Bread& bread);
	~Bread() {};
	//Bread 하나를 소모하여 hp를 5 회복
	void use();
	Item* copy();
};
