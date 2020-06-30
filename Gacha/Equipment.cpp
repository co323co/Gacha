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
	cout << "착용할 장비를 입력해주세요" << endl << ">>";
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
		cout << "아이템을 찾을 수 없습니다" << endl;
		return;
	}
	switch (item->type)
	{

	case EnumCode::equipCode::head:
		if (head == NULL)
		{
			cout << item->getName() << " 장착" << endl;
			head = item;
			head->putOn();
			break;
		}
		else
		{
			head->takeOff();
			cout << head->getName() << " 해제" << endl;
			head = item;
			head->putOn();
			cout << item->getName() << " 장착" << endl;
			break;
		}
		break;
	case EnumCode::equipCode::weapon:
		if (weapon == NULL)
		{
			cout << item->getName() << " 장착" << endl;
			weapon = item;
			weapon->putOn();
			break;
		}
		else
		{
			weapon->takeOff();
			cout << weapon->getName() << " 해제" << endl;
			weapon = item;
			weapon->putOn();
			cout << item->getName() << " 장착" << endl;
			break;
		}
		break;
	case EnumCode::equipCode::armor:
		if (armor == NULL)
		{
			cout << item->getName() << " 장착" << endl;
			armor = item;
			armor->putOn();
			break;
		}
		else
		{
			armor->takeOff();
			cout << armor->getName() << " 해제" << endl;
			armor = item;
			armor->putOn();
			cout << item->getName() << " 장착" << endl;
			break;
		}
		break;
	default:
		cout << "착용할 수 없는 아이템" << endl;
		break;
	}
}
void Equipment::takeOffEuipment()

{
	cout << "장착 해제할 부위를 골라주세요" << endl;
	cout << "1.head		2.armor		 3.weapon		4.취소" << endl;
	cout << ">>";
	int input;
	cin >> input;
	switch (input)
	{
	case 1:
		if (head == NULL)
		{
			cout << "이미 장착한 것이 없습니다." << endl;
			break;
		}
		head->takeOff();
		cout << head->getName() << " 해제" << endl;
		head = NULL;
		break;
	case 2:
		if (armor == NULL)
		{
			cout << "이미 장착한 것이 없습니다." << endl;
			break;
		}
		armor->takeOff();
		cout << armor->getName() << " 해제" << endl;
		armor = NULL;
		break;
	case 3:
		if (weapon == NULL)
		{
			cout << "이미 장착한 것이 없습니다." << endl;
			break;
		}
		weapon->takeOff();
		cout << weapon->getName() << " 해제" << endl;
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