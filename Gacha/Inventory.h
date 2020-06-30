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
	//�Ҹ��� ���� delete ����
	~Inventory();
	vector<Item*> poket;

	//�������� �������� Ȯ���ϴ� �Լ�. ������ ��� �ε�����, ������ �ʾ��� ��� -1 ����
	int hasItem(Item* item);
	Item* find(string name);
	bool add(Item* item);
	bool add(Item* item, int amount);
	bool sub(Item* item);
	bool sub(Item* item, int amount);
	void print();
	void useItem();
};
