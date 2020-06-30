#pragma once
#include"Player.h"
#include"EnumCode.h"
#include<string>

using namespace std;

class Item
{

protected:
	Player* player = &Player::inst;
	string name;
	//maxQuantity�� ����, �ڽ� Ŭ�������� ���� ���� ���ϸ� 99�� �ȴ�.
	int maxQ = 99;
public:
	int value = 0;
	EnumCode::itemCode code;
	EnumCode::equipCode type = EnumCode::equipCode::none;
	int currentQ;
	bool canUse = false;
	Item();
	Item(Item& item);
	virtual ~Item() {};
	string getName() const;
	int getMaxQ() const;
	virtual void use();
	virtual void putOn() {}
	virtual void takeOff() {}
	virtual Item* copy();
};
