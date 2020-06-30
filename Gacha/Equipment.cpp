#include"Equipment.h"
#include"Inventory.h"
#include"Item.h"
Equipment::Equipment(Inventory* inventory)
{
	head = NULL;
	weapon = NULL;
	armor = NULL;
	inven = inventory;
}
void Equipment::putOnEuipment()
{
	Item* item = NULL;
	string input;
	cout << "������ ��� �Է����ּ���" << endl << ">>";
	cin >> input;
	for (int i = 0; i < inven->poket.size(); i++)
	{
		if (inven->poket[i]->getName().compare(input) == 0)
		{
			item = inven->poket[i];
			break;
		}
	}
	if (item == NULL)
	{
		cout << "�������� ã�� �� �����ϴ�" << endl;
		return;
	}
	switch (item->type)
	{

	case EnumCode::equipCode::head:
		if (head == NULL)
		{
			cout << item->getName() << " ����" << endl;
			head = item;
			head->putOn();
			break;
		}
		else
		{
			head->takeOff();
			cout << head->getName() << " ����" << endl;
			head = item;
			head->putOn();
			cout << item->getName() << " ����" << endl;
			break;
		}
		break;
	case EnumCode::equipCode::weapon:
		if (weapon == NULL)
		{
			cout << item->getName() << " ����" << endl;
			weapon = item;
			weapon->putOn();
			break;
		}
		else
		{
			weapon->takeOff();
			cout << weapon->getName() << " ����" << endl;
			weapon = item;
			weapon->putOn();
			cout << item->getName() << " ����" << endl;
			break;
		}
		break;
	case EnumCode::equipCode::armor:
		if (armor == NULL)
		{
			cout << item->getName() << " ����" << endl;
			armor = item;
			armor->putOn();
			break;
		}
		else
		{
			armor->takeOff();
			cout << armor->getName() << " ����" << endl;
			armor = item;
			armor->putOn();
			cout << item->getName() << " ����" << endl;
			break;
		}
		break;
	default:
		cout << "������ �� ���� ������" << endl;
		break;
	}
}
void Equipment::takeOffEuipment()

{
	cout << "���� ������ ������ ����ּ���" << endl;
	cout << "1.head		2.armor		 3.weapon		4.���" << endl;
	cout << ">>";
	int input;
	cin >> input;
	switch (input)
	{
	case 1:
		if (head == NULL)
		{
			cout << "�̹� ������ ���� �����ϴ�." << endl;
			break;
		}
		head->takeOff();
		cout << head->getName() << " ����" << endl;
		head = NULL;
		break;
	case 2:
		if (armor == NULL)
		{
			cout << "�̹� ������ ���� �����ϴ�." << endl;
			break;
		}
		armor->takeOff();
		cout << armor->getName() << " ����" << endl;
		armor = NULL;
		break;
	case 3:
		if (weapon == NULL)
		{
			cout << "�̹� ������ ���� �����ϴ�." << endl;
			break;
		}
		weapon->takeOff();
		cout << weapon->getName() << " ����" << endl;
		weapon = NULL;
		break;
	default:
		break;
	}
}
void Equipment::print()
{
	string headItem, weaponItem, armorItem;

	if (head == NULL) headItem = "";
	else headItem = head->getName();

	if (weapon == NULL) weaponItem = "";
	else weaponItem = weapon->getName();

	if (armor == NULL) armorItem = "";
	else armorItem = armor->getName();

	cout << "head : " << headItem << endl;
	cout << "armor : " << armorItem << endl;
	cout << "weapon : " << weaponItem << endl;
}