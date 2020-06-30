#pragma once
#include<iostream>
#include<map>
#include"EnumCode.h"
#include"ItemList.h"

using namespace std;

class ItemManager
{
private:
	static ItemManager* inst;
	ItemManager();
public:
	typedef EnumCode::itemCode Code;
	static ItemManager* getInst();
	static map<Code, Item*> data;
	void addItem(Item* item);
	void printData();
	//코드를 넘겨주면 IM이 갖고있는 아이템을 복사해서 넘겨주는 식
	Item* getItem(Code);
};
