#pragma once
#include<Windows.h>
#include"Environment.h"
#include"InvenHeaderList.h"
#include"Shop.h"
#include"Gacha.h"
using namespace std;
void Environment::loop()
{
	Player* player = &Player::inst;
	Inventory* inven = player->inventory;
	Shop* shop = new Shop;
	Gacha* gacha = new Gacha;
	player->setHp(50);
	inven->add(new Gold(100));
	int input;
	while (true)
	{
		system("cls");
		cout << "---------------------------------------------------------------" << endl;
		cout << "1.상태창	";
		cout << "2.상점		";
		cout << "3.가챠		";
		cout << "4.돌아가기		" << endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << ">> ";
		cin >> input;
		switch (input)
		{
			//상태창
		case 1:
			while (true)
			{
				system("cls");
				player->printStatus();
				inven->print();
				inven->eq->print();
				cout << "---------------------------------------------------------------" << endl;
				cout << "1.장비 착용		";
				cout << "2.장비 해제		" << endl;
				cout << "3.아이템 사용		";
				cout << "4.돌아가기			" << endl;
				cout << "---------------------------------------------------------------" << endl;
				cout << ">> ";
				cin >> input;
				if (input == 1)
				{
					inven->eq->putOnEuipment();
					char input;
					cout << "넘어가려면 아무 키나 입력하세요. >> ";
					cin >> input;
				}
				else if (input == 2)
				{
					inven->eq->takeOffEuipment();
					char input;
					cout << "넘어가려면 아무 키나 입력하세요. >> ";
					cin >> input;
				}
				else if (input == 3)
				{
					inven->useItem();
					char input;
					cout << "넘어가려면 아무 키나 입력하세요. >> ";
					cin >> input;

				}
				else
				{
					break;
				}
			}
			break;
			//상점
		case 2:
			while (true)
			{
				system("cls");
				if (-1 == shop->menu())
				{
					system("cls");
					break;
				}
				char input;
				cout << "넘어가려면 아무 키나 입력하세요. >> ";
				cin >> input;
			}
			break;
			//가챠
		case 3:
			while (true)
			{
				system("cls");
				if (-1 == gacha->menu())
				{
					system("cls");
					break;
				}
				char input;
				cout << "넘어가려면 아무 키나 입력하세요. >> ";
				cin >> input;
			}
			break;
			//돌아가기
		case 4:
			return;
		default:
			break;
		}
	}

}