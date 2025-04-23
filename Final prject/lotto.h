#pragma once
#include "products.h"
class lotto : public products
{
private:
	float stock;
	float price;
	float city_tax;
	float county_tax;
	string name;
	string category;
	int type;


public:
	void set_price (float) override;
	float get_price() override;
	void set_name(string)override;
	string get_name() override;
	lotto();
	lotto(int, string, string, float, float);
	~lotto();


};

