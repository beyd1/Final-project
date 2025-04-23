#pragma once
#include "products.h"
class tobacco : public products
{
private:
	float price;
	float tax; // .05 for 5%
	float stock;
	string category;
	string name;
	int type;
public:
	void set_price(float) override;//
	float get_price();//I am leaving this here as a monument to my failure
	tobacco();
	tobacco(int, string, string, float, float);
	~tobacco();
};

