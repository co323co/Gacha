#pragma once
#include "Item.h"

class Potion : public Item
{
	int healingAmount = 30;
public:
	Potion();
	Potion(Potion& potion);
	~Potion() {};
	//Potion �ϳ��� �Ҹ��Ͽ� hp�� 30 ȸ��
	void use();
	Item* copy();
};
