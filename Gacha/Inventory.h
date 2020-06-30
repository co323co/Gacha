#pragma once
#include<iomanip>
#include<vector>

using namespace std;

class Item;
class Equipment;

class Inventory
{
public:
	Equipment* eq;
	Inventory();
	//소멸자 벡터 delete 내용
	~Inventory();
	vector<Item*> poket;

	//아이템을 가졌는지 확인하는 함수. 가졌을 경우 인덱스를, 가지지 않았을 경우 -1 리턴
	int hasItem(Item* item);
	Item* find(string name);
	bool add(Item* item);
	bool add(Item* item, int amount);
	bool sub(Item* item);
	bool sub(Item* item, int amount);
	void print();
	void useItem();
};
