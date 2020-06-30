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
	//�ڵ带 �Ѱ��ָ� IM�� �����ִ� �������� �����ؼ� �Ѱ��ִ� ��
	Item* getItem(Code);
};
