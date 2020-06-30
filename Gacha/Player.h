#pragma once
#include<iostream>
#include<iomanip>

using namespace std;

class Inventory;

class Player
{
private:
	int hp;
	float att = 100;
	float def = 100;
	Player();
	~Player();
public:
	static Player inst;
	static Inventory* inventory;
	int maxHp = 100;
	int getHp() const;
	void setHp(int hp);
	void addHp(int hp);
	float getAtt() const;
	void setAtt(float att);
	float getDef() const;
	void setDef(float def);
	void printStatus();
};