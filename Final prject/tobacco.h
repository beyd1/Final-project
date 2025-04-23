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

	tobacco();
	tobacco(int, string, string, float, float);
	~tobacco();
	float compute_price();
};

