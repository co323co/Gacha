#pragma once
#include "Item.h"

class Bread : public Item
{
	int healingAmount = 5;
public:
	Bread();
	Bread(Bread& bread);
	~Bread() {};
	//Bread �ϳ��� �Ҹ��Ͽ� hp�� 5 ȸ��
	void use();
	Item* copy();
};
