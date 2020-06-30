#pragma once
#include"Potion.h"

Potion::Potion()
{
	code = EnumCode::itemCode::Potion;
	name = "포션";
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
	//사용하면 수량 줄어듬
	if (--currentQ < 0) return;
	cout << "----------------------------------------" << endl;
	cout << "포션 사용 hp + " << healingAmount << endl;
	cout << "----------------------------------------" << endl;
	player->addHp(healingAmount);
}
Item* Potion::copy()
{
	return new Potion(*this);
}

