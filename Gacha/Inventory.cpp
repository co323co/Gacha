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
	//��ȸ�Ͽ� �̹� �ִ��� ������, maxQ�� ������ üũ
	//������ �ְ� ����
	if (index == -1)
	{
		poket.push_back(tmp);
		return true;
	}
	//�̹� �ִ������ �������� ����
	if (poket[index]->currentQ >= poket[index]->getMaxQ())
	{
		cout << "[" << poket[index]->getName() << "]�� �� �̻� ���� �� �����ϴ�." << endl;
		return false;
	}
	//������ ������ �������� ���� ����
	poket[index]->currentQ++;
	return true;
}
bool Inventory::add(Item* item, int amount)
{
	Item* tmp = item->copy();
	int index = hasItem(tmp);
	//��ȸ�Ͽ� �̹� �ִ��� ������, maxQ�� ������ üũ
	//������ �ְ� ����
	if (index == -1)
	{
		tmp->currentQ = amount;
		poket.push_back(tmp);
		return true;
	}
	//�̹� �ִ������ �������� ����
	if (poket[index]->currentQ + amount > poket[index]->getMaxQ())
	{
		poket[index]->currentQ = poket[index]->getMaxQ();
		cout << "[" << poket[index]->getName() << "]��" << poket[index]->getMaxQ() << "�� �̻� ���� �� �����ϴ�." << endl;
		return false;
	}
	//������ ������ �������� ���� ����
	poket[index]->currentQ += amount;
	return true;
}
bool Inventory::sub(Item* item)
{
	int index = hasItem(item);
	//�̹� ������ ������ ����
	if (index == -1)
	{
		cout << "[" << item->getName() << "]�� �κ��丮�� �����ϴ�." << endl;
		return false;
	}
	if (--poket[index]->currentQ == 0)  poket.erase(poket.begin() + index);

	return true;
}
bool Inventory::sub(Item* item, int amount)
{
	int index = hasItem(item);
	//�̹� ������ ������ ����
	if (index == -1)
	{
		cout << "[" << item->getName() << "]�� �κ��丮�� �����ϴ�." << endl;
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
	cout << "[�κ��丮]" << endl;
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
			//����� �� �ִ� �������� *ǥ��
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
	cout << "����� ������ �̸��� �Է����ּ���" << endl;
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
	cout << "�������� ã�� �� �����ϴ�." << endl;
	return;
}