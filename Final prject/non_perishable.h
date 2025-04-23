#pragma once
#include "products.h"
class non_perishable : public products
{
private:
	float price;
	float stock;
	string category;
	string name;
	int type;

public:

	non_perishable();
	non_perishable(int, string, string, float, float);

	//uses default compute price
};

