#pragma once
#include"Shop.h"
#include"InvenHeaderList.h"
#include"Player.h"

using namespace std;
Shop::Shop()
{
	inven = Player::inventory;
}
int Shop::menu()
{
	print();
	int input;
	while (true)
	{
		cout << "1. 구매하기		2.팔기		3.돌아가기" << endl;
		cout << "---------------------------------------------------------------" << endl << ">>";

		cin >> input;
		if (input == 1)
		{
			buy();
			return 1;
			break;
		}
		if (input == 2)
		{
			sell();
			return 2;
			break;
		}
		if (input == 3)
		{
			return -1;
		}
	}


}
void Shop::print()
{
	cout << "---------------------------------------------------------------" << endl;
	cout << "[상점]" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "1.활(50G)		";
	cout << "2.빵(3G)		";
	cout << "3.단검(70G)			" << endl;
	cout << "4.곡괭이(20G)		";
	cout << "5.포션(30G)		";
	cout << "6.갑옷(40G)		" << endl;
	cout << "---------------------------------------------------------------" << endl;
	inven->print();
}
void Shop::buy()
{
	int input;
	cout << "구매할 아이템을 선택해주세요" << endl;
	cout << ">>";
	cin >> input;
	Item* item = inven->find("골드");
	switch (input)
	{
	case 1:
		if (item == NULL)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		if (item->currentQ < 50)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		inven->add(new Bow);
		inven->sub(item, 50);
		break;
	case 2:
		if (item == NULL)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		if (item->currentQ < 3)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		inven->sub(inven->find("골드"), 3);
		inven->add(new Bread);
		break;
	case 3:
		if (item == NULL)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		if (item->currentQ < 70)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		inven->sub(inven->find("골드"), 70);
		inven->add(new Dagger);
		break;
	case 4:
		if (item == NULL)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		if (item->currentQ < 20)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		inven->sub(inven->find("골드"), 20);
		inven->add(new Pickax);
		break;
	case 5:
		if (item == NULL)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		if (item->currentQ < 30)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		inven->sub(inven->find("골드"), 30);
		inven->add(new Potion);
		break;
	case 6:
		if (item == NULL)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		if (item->currentQ < 40)
		{
			cout << "골드가 부족합니다." << endl;
			break;
		}
		inven->sub(inven->find("골드"), 40);
		inven->add(new Mail);
		break;
	default:
		cout << "잘못 입력하셨습니다." << endl;
		break;
	}
}

void Shop::sell()
{
	int input;
	cout << "판매 할 아이템을 선택해주세요" << endl;
	cout << ">>";
	cin >> input;
	switch (input)
	{
	case 1:
		if (inven->eq->weapon != NULL)
		{
			if (inven->eq->weapon->getName().compare("활") == 0)
			{
				cout << "착용중인 물건은 팔 수 없습니다." << endl;
				break;
			}
		}
		if (inven->find("활") == NULL)
		{
			cout << "보유하고 있지 않습니다" << endl;
			break;
		}
		inven->sub(inven->find("활"));
		inven->add(new Gold, 50);

		break;
	case 2:
		if (inven->find("빵") == NULL)
		{
			cout << "보유하고 있지 않습니다" << endl;
			break;
		}
		inven->sub(inven->find("빵"));
		inven->add(new Gold, 3);
		break;
	case 3:
		if (inven->eq->weapon != NULL)
		{
			if (inven->eq->weapon->getName().compare("단검") == 0)
			{
				cout << "착용중인 물건은 팔 수 없습니다." << endl;
				break;
			}
		}
		if (inven->find("단검") == NULL)
		{
			cout << "보유하고 있지 않습니다" << endl;
			break;
		}
		inven->sub(inven->find("단검"));
		inven->add(new Gold, 70);
		break;
	case 4:
		if (inven->eq->weapon != NULL)
		{
			if (inven->eq->weapon->getName().compare("곡괭이") == 0)
			{
				cout << "착용중인 물건은 팔 수 없습니다." << endl;
				break;
			}
		}
		if (inven->find("곡괭이") == NULL)
		{
			cout << "보유하고 있지 않습니다" << endl;
			break;
		}
		inven->sub(inven->find("곡괭이"));
		inven->add(new Gold, 20);
		break;
	case 5:
		if (inven->find("포션") == NULL)
		{
			cout << "보유하고 있지 않습니다" << endl;
			break;
		}
		inven->sub(inven->find("포션"));
		inven->add(new Gold, 30);
		break;
	case 6:
		if (inven->eq->armor != NULL)
		{
			if (inven->eq->armor->getName().compare("갑옷") == 0)
			{
				cout << "착용중인 물건은 팔 수 없습니다." << endl;
				break;
			}
		}
		if (inven->find("갑옷") == NULL)
		{
			cout << "보유하고 있지 않습니다" << endl;
			break;
		}
		inven->sub(inven->find("갑옷"));
		inven->add(new Gold, 40);
		break;
	default:
		break;
	}
}
