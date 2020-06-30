#pragma once
#include"ItemManager.h"

ItemManager* ItemManager::inst = NULL;
map<EnumCode::itemCode, Item*> ItemManager::data;
ItemManager* ItemManager::getInst()
{
	if (inst == NULL) inst = new ItemManager;
	return inst;
}
ItemManager::ItemManager()
{
	addItem(new Bow);
	addItem(new Bread);
	addItem(new Dagger);
	addItem(new Gold);
	addItem(new Mail);
	addItem(new Pickax);
	addItem(new Potion);
}
void ItemManager::addItem(Item* item)
{
	data[item->code] = item;
}
void ItemManager::printData()
{
	cout << "<아이템 매니저>" << endl;
	map<Code, Item*>::iterator it;
	for (it = data.begin(); it != data.end(); it++)
	{
		cout << "[" << it->first << "," << it->second->getName() << "]" << endl;
	}
}

Item* ItemManager::getItem(Code code)
{
	return data[code]->copy();
}