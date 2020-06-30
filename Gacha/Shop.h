#pragma once
#include<iostream>

class Inventory;

class Shop
{
public:
	Shop();
	~Shop() {};
	Inventory* inven;
	void print();
	int menu();
	void buy();
	void sell();
};