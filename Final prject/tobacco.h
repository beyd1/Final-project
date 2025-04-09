#pragma once
#include "products.h"
class tobacco : public products
{
private:
	float price;
	float tax; // .05 for 5%

public:
	void set_price(float);//**
	float get_price();//**


};

