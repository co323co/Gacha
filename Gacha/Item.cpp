#pragma once
#include"Item.h"
#include"ItemManager.h"
Item::Item()
{
	currentQ = 1;

}

Item::Item(Item& item)
{
	name = item.getName();
	maxQ = item.getMaxQ();
	value = item.value;
	code = item.code;
	type = item.type;
	currentQ = item.currentQ;
	canUse = item.canUse;
}

string Item::getName() const
{
	return name;
}
int Item::getMaxQ() const
{
	return maxQ;
}
void Item::use()
{
	cout << "사용할 수 없는 아이템 입니다" << endl;
}

Item* Item::copy()
{
	return new Item(*this);
}
