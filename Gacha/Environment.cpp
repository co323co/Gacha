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
		cout << "1.����â	";
		cout << "2.����		";
		cout << "3.��í		";
		cout << "4.���ư���		" << endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << ">> ";
		cin >> input;
		switch (input)
		{
			//����â
		case 1:
			while (true)
			{
				system("cls");
				player->printStatus();
				inven->print();
				inven->eq->print();
				cout << "---------------------------------------------------------------" << endl;
				cout << "1.��� ����		";
				cout << "2.��� ����		" << endl;
				cout << "3.������ ���		";
				cout << "4.���ư���			" << endl;
				cout << "---------------------------------------------------------------" << endl;
				cout << ">> ";
				cin >> input;
				if (input == 1)
				{
					inven->eq->putOnEuipment();
					char input;
					cout << "�Ѿ���� �ƹ� Ű�� �Է��ϼ���. >> ";
					cin >> input;
				}
				else if (input == 2)
				{
					inven->eq->takeOffEuipment();
					char input;
					cout << "�Ѿ���� �ƹ� Ű�� �Է��ϼ���. >> ";
					cin >> input;
				}
				else if (input == 3)
				{
					inven->useItem();
					char input;
					cout << "�Ѿ���� �ƹ� Ű�� �Է��ϼ���. >> ";
					cin >> input;

				}
				else
				{
					break;
				}
			}
			break;
			//����
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
				cout << "�Ѿ���� �ƹ� Ű�� �Է��ϼ���. >> ";
				cin >> input;
			}
			break;
			//��í
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
				cout << "�Ѿ���� �ƹ� Ű�� �Է��ϼ���. >> ";
				cin >> input;
			}
			break;
			//���ư���
		case 4:
			return;
		default:
			break;
		}
	}

}