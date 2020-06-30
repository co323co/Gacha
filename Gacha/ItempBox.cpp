#include<cstdlib>
#include<ctime>
#include"ItemBox.h"
#include"ItemManager.h"

ItemBox::ItemBox(string name, int cost, Code code, int num)
{
	boxName = name;
	boxCost = cost;
	Item* item = ItemManager::getInst()->getItem(code);
	item->currentQ = num;
	itemForm form;
	form.item = item;
	form.raito = 100;
	itemVector.push_back(form);
}
ItemBox::~ItemBox() {}
void ItemBox::setDefaultItem(Code code, int num)
{
	Item* item = ItemManager::getInst()->getItem(code);
	item->currentQ = num;
	itemVector[0].item = item;
}

void ItemBox::addItem(Code code, float ratio, int num)
{
	Item* item = ItemManager::getInst()->getItem(code);
	item->currentQ = num;
	itemForm form;
	form.item = item;
	form.raito = ratio;
	itemVector.push_back(form);
	itemVector[0].raito -= ratio;
}

Item* ItemBox::openBox()
{
	vector<itemForm> v(itemVector);
	//버블 정렬
	int i, j, n = v.size();
	itemForm temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (v[j].raito > v[j + 1].raito)
			{
				temp.raito = v[j].raito;
				temp.item = v[j].item;
				v[j].raito = v[j + 1].raito;
				v[j].item = v[j + 1].item;
				v[j + 1].raito = temp.raito;
				v[j + 1].item = temp.item;
			}
		}
	}
	srand(time(NULL));
	int ran = rand() % 100;
	/* ex)
		아이템 확률 10 20 30 40
		ran의 값
			0~9 //10
			10~29 //20
			30~59 //30
			60~99 //40
	*/
	//cout << "ran : " << ran << endl;
	float ratio = v[0].raito;
	for (int i = 0; i < v.size(); i++)
	{
		//cout << i << "번째 " << ratio << endl;
		if (ran < ratio) return v[i].item;
		ratio += v[i + 1].raito;
	}
	vector<itemForm>::iterator it;
	return v.back().item;
}

void ItemBox::printBox()
{
	vector<itemForm>::iterator it;
	for (it = itemVector.begin(); it != itemVector.end(); it++)
	{
		cout << (*it).item->getName() << "(" << (*it).item->currentQ << ") >> " << (*it).raito << "%" << endl;
	}
}