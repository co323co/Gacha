#include"Gacha.h"
#include"Player.h"
#include"InvenHeaderList.h"
#include<Windows.h>
Gacha::Gacha()
{
	ItemBox* A = new ItemBox("A", 10, Code::Gold, 5);
	A->addItem(Code::Bread, 30);
	A->addItem(Code::Potion, 40);
	A->addItem(Code::Dagger, 10);
	boxVector.push_back(A);

	ItemBox* B = new ItemBox("B", 20, Code::Gold, 10);
	B->addItem(Code::Bread, 20, 3);
	B->addItem(Code::Pickax, 20);
	B->addItem(Code::Bow, 30);
	boxVector.push_back(B);

}

int Gacha::menu()
{
	showGacha();
	int input;
	while (true)
	{
		cout << "1. 상자 뽑기		2.돌아가기		" << endl;
		cout << "---------------------------------------------------------------" << endl << ">>";
		cin >> input;
		if (input == 1)
		{
			pickBox();
			return 1;
			break;
		}
		if (input == 2)
		{
			return -1;
		}
	}


}
void Gacha::showGacha()
{
	cout << "---------------------------------------------------------------" << endl;
	cout << "현재 판매중인 상자는 [" << boxVector.size() << "]종류 입니다." << endl;
	int i = 0;
	vector<ItemBox*>::iterator it;
	for (it = boxVector.begin(); it != boxVector.end(); it++)
	{
		if (it == boxVector.begin())
			cout << "------------------------------------------" << endl;
		cout << "[" << i << "]번째 상자 : " << (*it)->boxName << " (" << (*it)->boxCost << "G)" << endl;
		cout << "------------------------------------------" << endl;
		(*it)->printBox();
		cout << "------------------------------------------" << endl;
		i++;
	}

	Player::inventory->print();

}
void Gacha::pickBox()
{
	Item* gold = Player::inventory->find("골드");

	int input;
	cout << "몇 번째 상자를 뽑으시겠습니까?" << endl << ">>";
	cin >> input;
	//범위 벗어나면 다시 입력받음
	while (input < 0 || input >= boxVector.size())
	{
		cout << ">>";
		cin >> input;
	}
	if (gold->currentQ < boxVector[input]->boxCost)
	{
		cout << "골드가 부족합니다" << endl;
		return;
	}
	Player::inventory->sub(new Gold, boxVector[input]->boxCost);

	system("cls");
	showGacha();
	cout << "상자를 구매했습니다." << endl;
	cout << "두근두근 상자를 열겠습니다!" << endl;
	char c;
	cout << "넘어가려면 아무 키나 입력하세요. >> ";
	cin >> c;

	Item* item = boxVector[input]->openBox();
	Player::inventory->add(item, item->currentQ);
	system("cls");
	showGacha();
	cout << "와! 신난다!" << endl << item->getName() << "(" << item->currentQ << ")을 얻었습니다!" << endl;
}

