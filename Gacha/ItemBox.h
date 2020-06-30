#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"EnumCode.h"

using namespace std;
class Item;

class ItemBox
{
public:
	typedef EnumCode::itemCode Code;
	string boxName;
	int boxCost;
	typedef struct
	{
		Item* item;
		float raito;
	}itemForm;
	//0번째 아이템이 디폴트 아이템
	vector<itemForm> itemVector;
	ItemBox(string name, int cost, Code code, int num);
	virtual ~ItemBox();
	void setDefaultItem(Code code, int num);
	void addItem(Code code, float ratio, int num = 1);
	Item* openBox();
	void printBox();
};