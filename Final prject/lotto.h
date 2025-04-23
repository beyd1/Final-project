#pragma once
#include "products.h"
class lotto : public products
{
private:
	float stock;
	float price;
	float city_tax = 0.0;
	float county_tax = 0.0;
	string name;
	string category;
	int type;


public:

	lotto();
	lotto(int, string, string, float, float);
	~lotto();
	//setters and getters in products.h

	float compute_price();
};

