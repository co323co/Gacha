#pragma once
#include "Item.h"

class Mail : public Item
{
public:
	Mail();
	Mail(Mail& mail);
	~Mail() {};
	//Def¸¦ +20
	void putOn();
	void takeOff();
	Item* copy();
};
