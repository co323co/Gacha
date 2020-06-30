#include<iostream>
#include"Environment.h"
using namespace std;

int main()
{
	Environment* evn = new Environment;
	evn->loop();
}