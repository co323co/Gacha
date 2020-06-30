#pragma once
#include"Inventory.h"
#include"Equipment.h"
#include"ItemList.h"

Inventory::Inventory()
{
	eq = new Equipment(this);
}
Inventory::~Inventory()
{
	delete(eq);
}
int Inventory::hasItem(Item* item)
{
	for (int i = 0; i < poket.size(); i++)
	{
		if (item->getName().compare(poket[i]->getName()) == 0) return i;
	}
	return -1;
}

Item* Inventory::find(string name)
{
	if (poket.size() == 0) return NULL;

	for (int i = 0; i < poket.size(); i++)
	{
		if (poket[i]->getName().compare(name) == 0) return poket[i];

	}
	return NULL;

}

bool Inventory::add(Item* item)
{
	Item* tmp = item->copy();
	int index = hasItem(tmp);
	//순회하여 이미 있는지 없는지, maxQ는 몇인지 체크
	//없으면 넣고 리턴
	if (index == -1)
	{
		poket.push_back(tmp);
		return true;
	}
	//이미 최대수량을 가졌으면 리턴
	if (poket[index]->currentQ >= poket[index]->getMaxQ())
	{
		cout << "[" << poket[index]->getName() << "]을 더 이상 가질 수 없습니다." << endl;
		return false;
	}
	//가지되 수량은 남았으면 수량 증가
	poket[index]->currentQ++;
	return true;
}
bool Inventory::add(Item* item, int amount)
{
	Item* tmp = item->copy();
	int index = hasItem(tmp);
	//순회하여 이미 있는지 없는지, maxQ는 몇인지 체크
	//없으면 넣고 리턴
	if (index == -1)
	{
		tmp->currentQ = amount;
		poket.push_back(tmp);
		return true;
	}
	//이미 최대수량을 가졌으면 리턴
	if (poket[index]->currentQ + amount > poket[index]->getMaxQ())
	{
		poket[index]->currentQ = poket[index]->getMaxQ();
		cout << "[" << poket[index]->getName() << "]을" << poket[index]->getMaxQ() << "개 이상 가질 수 없습니다." << endl;
		return false;
	}
	//가지되 수량은 남았으면 수량 증가
	poket[index]->currentQ += amount;
	return true;
}
bool Inventory::sub(Item* item)
{
	int index = hasItem(item);
	//이미 가진게 없으면 리턴
	if (index == -1)
	{
		cout << "[" << item->getName() << "]가 인벤토리에 없습니다." << endl;
		return false;
	}
	if (--poket[index]->currentQ == 0)  poket.erase(poket.begin() + index);

	return true;
}
bool Inventory::sub(Item* item, int amount)
{
	int index = hasItem(item);
	//이미 가진게 없으면 리턴
	if (index == -1)
	{
		cout << "[" << item->getName() << "]가 인벤토리에 없습니다." << endl;
		return false;
	}
	if (poket[index]->currentQ - amount <= 0)
	{
		poket.erase(poket.begin() + index);
		return true;
	}
	poket[index]->currentQ -= amount;
	return true;
}
void Inventory::print()
{
	cout << "---------------------------------------------------------------" << endl;
	cout << "[인벤토리]" << endl;
	for (int i = 0; i < poket.size(); i++)
	{
		if (poket[i]->currentQ <= 0) poket.erase(poket.begin() + i);

		if (poket[i]->canUse == false)
		{
			//cout << right;
			cout << setw(10) << poket[i]->getName() << "(" << poket[i]->currentQ << ")";

		}
		else
		{
			//cout << right;
			//사용할 수 있는 아이템은 *표시
			cout << setw(10) << poket[i]->getName() << "(" << poket[i]->currentQ << ")*";
		}
		if ((i + 1) % 3 == 0 && i != poket.size() - 1) cout << endl;
	}
	cout << endl;
	cout << "---------------------------------------------------------------" << endl;
}
void Inventory::useItem()
{
	string input;
	cout << "사용할 아이템 이름을 입력해주세요" << endl;
	cout << ">>";
	cin >> input;
	for (int i = 0; i < poket.size(); i++)
	{
		if (poket[i]->getName().compare(input) == 0)
		{
			poket[i]->use();
			return;
		}
	}
	cout << "아이템을 찾을 수 없습니다." << endl;
	return;
}