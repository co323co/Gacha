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
		cout << "1. ���� �̱�		2.���ư���		" << endl;
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
	cout << "���� �Ǹ����� ���ڴ� [" << boxVector.size() << "]���� �Դϴ�." << endl;
	int i = 0;
	vector<ItemBox*>::iterator it;
	for (it = boxVector.begin(); it != boxVector.end(); it++)
	{
		if (it == boxVector.begin())
			cout << "------------------------------------------" << endl;
		cout << "[" << i << "]��° ���� : " << (*it)->boxName << " (" << (*it)->boxCost << "G)" << endl;
		cout << "------------------------------------------" << endl;
		(*it)->printBox();
		cout << "------------------------------------------" << endl;
		i++;
	}

	Player::inventory->print();

}
void Gacha::pickBox()
{
	Item* gold = Player::inventory->find("���");

	int input;
	cout << "�� ��° ���ڸ� �����ðڽ��ϱ�?" << endl << ">>";
	cin >> input;
	//���� ����� �ٽ� �Է¹���
	while (input < 0 || input >= boxVector.size())
	{
		cout << ">>";
		cin >> input;
	}
	if (gold->currentQ < boxVector[input]->boxCost)
	{
		cout << "��尡 �����մϴ�" << endl;
		return;
	}
	Player::inventory->sub(new Gold, boxVector[input]->boxCost);

	system("cls");
	showGacha();
	cout << "���ڸ� �����߽��ϴ�." << endl;
	cout << "�αٵα� ���ڸ� ���ڽ��ϴ�!" << endl;
	char c;
	cout << "�Ѿ���� �ƹ� Ű�� �Է��ϼ���. >> ";
	cin >> c;

	Item* item = boxVector[input]->openBox();
	Player::inventory->add(item, item->currentQ);
	system("cls");
	showGacha();
	cout << "��! �ų���!" << endl << item->getName() << "(" << item->currentQ << ")�� ������ϴ�!" << endl;
}

