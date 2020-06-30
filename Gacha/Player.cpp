#pragma once
#include"Player.h"
#include"Inventory.h"
Player Player::inst;
Inventory* Player::inventory = new Inventory;
Player::Player()
{
	hp = maxHp;
}
Player::~Player()
{

	delete(inventory);

}
int Player::getHp() const
{
	return hp;
}
void Player::setHp(int hp)
{
	if (hp < 0)
	{
		this->hp = 0;
		return;
	}
	if (hp > maxHp)
	{
		this->hp = maxHp;
		return;
	}
	this->hp = hp;
}
void Player::addHp(int hp)
{
	if (this->hp + hp < 0)
	{
		this->hp = 0;
		return;
	}
	if (this->hp + hp > maxHp)
	{
		this->hp = maxHp;
		return;
	}
	this->hp += hp;
}

float Player::getAtt() const
{
	return att;
}
void Player::setAtt(float att)
{
	if (att < 0)
	{
		this->att = 0;
		return;
	}
	this->att = att;
}
float Player::getDef() const
{
	return def;
}
void Player::setDef(float def)
{
	if (def < 0)
	{
		this->def = 0;
		return;
	}
	this->def = def;
}
void Player::printStatus()
{
	cout << "--------------------------------------------------" << endl;
	cout << "[ป๓ลย]" << endl;
	cout << setw(10) << "HP : " << hp << "/" << maxHp << endl;
	cout << setw(10) << "ATT : " << att << endl;
	cout << setw(10) << "DEF : " << def << endl;
	cout << "--------------------------------------------------" << endl;
}