#pragma once
#include"Dagger.h"

Dagger::Dagger()
{
	code = EnumCode::itemCode::Dagger;
	type = EnumCode::equipCode::weapon;
	name = "´Ü°Ë";
	value = 70;
}
Dagger::Dagger(Dagger& dagger) : Item(dagger)
{
	Dagger();
}
void Dagger::putOn()
{
	player->setAtt(player->getAtt() * 1.2);
}
void Dagger::takeOff()
{
	if (player->getAtt() == 0) return;
	player->setAtt(player->getAtt() / 1.2);
}
Item* Dagger::copy()
{
	return new Dagger(*this);
}

