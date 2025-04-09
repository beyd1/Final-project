#pragma once
#include "products.h"
class lotto : public products
{
private:
	float price;
	float city_tax;
	float county_tax;

public:
	void set_price(float);
	float get_price();

};

