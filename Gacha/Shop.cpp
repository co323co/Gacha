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
		cout << "1. �����ϱ�		2.�ȱ�		3.���ư���" << endl;
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
	cout << "[����]" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "1.Ȱ(50G)		";
	cout << "2.��(3G)		";
	cout << "3.�ܰ�(70G)			" << endl;
	cout << "4.���(20G)		";
	cout << "5.����(30G)		";
	cout << "6.����(40G)		" << endl;
	cout << "---------------------------------------------------------------" << endl;
	inven->print();
}
void Shop::buy()
{
	int input;
	cout << "������ �������� �������ּ���" << endl;
	cout << ">>";
	cin >> input;
	Item* item = inven->find("���");
	switch (input)
	{
	case 1:
		if (item == NULL)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		if (item->currentQ < 50)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		inven->add(new Bow);
		inven->sub(item, 50);
		break;
	case 2:
		if (item == NULL)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		if (item->currentQ < 3)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		inven->sub(inven->find("���"), 3);
		inven->add(new Bread);
		break;
	case 3:
		if (item == NULL)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		if (item->currentQ < 70)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		inven->sub(inven->find("���"), 70);
		inven->add(new Dagger);
		break;
	case 4:
		if (item == NULL)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		if (item->currentQ < 20)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		inven->sub(inven->find("���"), 20);
		inven->add(new Pickax);
		break;
	case 5:
		if (item == NULL)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		if (item->currentQ < 30)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		inven->sub(inven->find("���"), 30);
		inven->add(new Potion);
		break;
	case 6:
		if (item == NULL)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		if (item->currentQ < 40)
		{
			cout << "��尡 �����մϴ�." << endl;
			break;
		}
		inven->sub(inven->find("���"), 40);
		inven->add(new Mail);
		break;
	default:
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		break;
	}
}

void Shop::sell()
{
	int input;
	cout << "�Ǹ� �� �������� �������ּ���" << endl;
	cout << ">>";
	cin >> input;
	switch (input)
	{
	case 1:
		if (inven->eq->weapon != NULL)
		{
			if (inven->eq->weapon->getName().compare("Ȱ") == 0)
			{
				cout << "�������� ������ �� �� �����ϴ�." << endl;
				break;
			}
		}
		if (inven->find("Ȱ") == NULL)
		{
			cout << "�����ϰ� ���� �ʽ��ϴ�" << endl;
			break;
		}
		inven->sub(inven->find("Ȱ"));
		inven->add(new Gold, 50);

		break;
	case 2:
		if (inven->find("��") == NULL)
		{
			cout << "�����ϰ� ���� �ʽ��ϴ�" << endl;
			break;
		}
		inven->sub(inven->find("��"));
		inven->add(new Gold, 3);
		break;
	case 3:
		if (inven->eq->weapon != NULL)
		{
			if (inven->eq->weapon->getName().compare("�ܰ�") == 0)
			{
				cout << "�������� ������ �� �� �����ϴ�." << endl;
				break;
			}
		}
		if (inven->find("�ܰ�") == NULL)
		{
			cout << "�����ϰ� ���� �ʽ��ϴ�" << endl;
			break;
		}
		inven->sub(inven->find("�ܰ�"));
		inven->add(new Gold, 70);
		break;
	case 4:
		if (inven->eq->weapon != NULL)
		{
			if (inven->eq->weapon->getName().compare("���") == 0)
			{
				cout << "�������� ������ �� �� �����ϴ�." << endl;
				break;
			}
		}
		if (inven->find("���") == NULL)
		{
			cout << "�����ϰ� ���� �ʽ��ϴ�" << endl;
			break;
		}
		inven->sub(inven->find("���"));
		inven->add(new Gold, 20);
		break;
	case 5:
		if (inven->find("����") == NULL)
		{
			cout << "�����ϰ� ���� �ʽ��ϴ�" << endl;
			break;
		}
		inven->sub(inven->find("����"));
		inven->add(new Gold, 30);
		break;
	case 6:
		if (inven->eq->armor != NULL)
		{
			if (inven->eq->armor->getName().compare("����") == 0)
			{
				cout << "�������� ������ �� �� �����ϴ�." << endl;
				break;
			}
		}
		if (inven->find("����") == NULL)
		{
			cout << "�����ϰ� ���� �ʽ��ϴ�" << endl;
			break;
		}
		inven->sub(inven->find("����"));
		inven->add(new Gold, 40);
		break;
	default:
		break;
	}
}
