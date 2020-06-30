#pragma once
#include"Potion.h"

Potion::Potion()
{
	code = EnumCode::itemCode::Potion;
	name = "����";
	maxQ = 5;
	canUse = true;
	value = 30;
}
Potion::Potion(Potion& potion) : Item(potion)
{
	Potion();
}
void Potion::use()
{
	//����ϸ� ���� �پ��
	if (--currentQ < 0) return;
	cout << "----------------------------------------" << endl;
	cout << "���� ��� hp + " << healingAmount << endl;
	cout << "----------------------------------------" << endl;
	player->addHp(healingAmount);
}
Item* Potion::copy()
{
	return new Potion(*this);
}

