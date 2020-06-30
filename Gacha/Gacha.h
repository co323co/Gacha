#pragma once
#include<vector>
#include"ItemBox.h"
#include"EnumCode.h"
using namespace std;

//class ItemBox;
class Gacha
{
public:
	typedef EnumCode::itemCode Code;
	vector<ItemBox*> boxVector;
	Gacha();
	~Gacha() {}
	void showGacha();
	void pickBox();
	int menu();
};