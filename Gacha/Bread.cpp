#pragma once
#include"Bread.h"

Bread::Bread()
{
	code = EnumCode::itemCode::Bread;
	name = "��";
	canUse = true;
	value = 3;

}

Bread::Bread(Bread& bread) : Item(bread)
{
	Bread();
}

void Bread::use()
{
	//����ϸ� ���� �پ��
	if (--currentQ < 0) return;
	cout << "----------------------------------------" << endl;
	cout << "�� ���� hp + " << healingAmount << endl;
	cout << "----------------------------------------" << endl;
	player->addHp(healingAmount);

}
Item* Bread::copy()
{
	return new Bread(*this);
}


