#pragma once
#include"Bread.h"

Bread::Bread()
{
	code = EnumCode::itemCode::Bread;
	name = "»§";
	canUse = true;
	value = 3;

}

Bread::Bread(Bread& bread) : Item(bread)
{
	Bread();
}

void Bread::use()
{
	//»ç¿ëÇÏ¸é ¼ö·® ÁÙ¾îµë
	if (--currentQ < 0) return;
	cout << "----------------------------------------" << endl;
	cout << "»§ º¹¿ë hp + " << healingAmount << endl;
	cout << "----------------------------------------" << endl;
	player->addHp(healingAmount);

}
Item* Bread::copy()
{
	return new Bread(*this);
}


