#pragma once
#include "Item.h"

class Potion : public Item
{
	int healingAmount = 30;
public:
	Potion();
	Potion(Potion& potion);
	~Potion() {};
	//Potion 하나를 소모하여 hp를 30 회복
	void use();
	Item* copy();
};
