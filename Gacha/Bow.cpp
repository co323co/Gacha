#pragma once
#include"Bow.h"

Bow::Bow()
{
	code = EnumCode::itemCode::Bow;
	type = EnumCode::equipCode::weapon;
	name = "활";
	value = 50;
}

Bow::Bow(Bow& bow) : Item(bow)
{
	Bow();
}

void Bow::putOn()
{
	player->setAtt(player->getAtt() * 2);

}
void Bow::takeOff()
{
	player->setAtt(player->getAtt() / 2);
}
Item* Bow::copy()
{
	return new Bow(*this);
}
