#pragma once
#include"Mail.h"

Mail::Mail()
{
	code = EnumCode::itemCode::Mail;
	name = "°©¿Ê";
	type = EnumCode::equipCode::armor;
	value = 50;
}
Mail::Mail(Mail& mail) : Item(mail)
{
	Mail();
}
void Mail::putOn()
{
	player->setDef(player->getDef() + 20);

}
void Mail::takeOff()
{
	player->setDef(player->getDef() - 20);
}

Item* Mail::copy()
{
	return new Mail(*this);
}
