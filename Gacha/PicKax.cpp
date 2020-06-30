#pragma once
#include "Pickax.h"

Pickax::Pickax()
{
	code = EnumCode::itemCode::Pickax;
	name = "°î±ªÀÌ";
	type = EnumCode::equipCode::weapon;
	maxQ = 1;
	value = 20;

}
Pickax::Pickax(Pickax& pickax) : Item(pickax)
{
	Pickax();
}
//°ø°Ý·Â 1 Áõ°¡
void Pickax::putOn()
{
	player->setAtt(player->getAtt() + 1);

}
void Pickax::takeOff()
{
	player->setAtt(player->getAtt() - 1);
}
Item* Pickax::copy()
{
	return new Pickax(*this);
}

