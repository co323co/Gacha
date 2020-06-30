#pragma once
#include"Gold.h"

Gold::Gold()
{
	code = EnumCode::itemCode::Gold;
	name = "°ñµå";
	maxQ = 9999999;
}
Gold::Gold(Gold& gold) : Item(gold)
{
	Gold();
}
Gold::Gold(int amount)
{
	name = "°ñµå";
	maxQ = 9999999;
	currentQ = amount;
}
Item* Gold::copy()
{
	return new Gold(*this);
}
