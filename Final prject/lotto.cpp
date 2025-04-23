#include "lotto.h"

void lotto::set_price (float price)
{
	products::set_price(price);
	float city = products::get_price() * city_tax;
	float county = products::get_price() * county_tax;
	price = price * (city + county);//I know this can be simplified
	//, but math is stupid so lets break it down.
	this->price = price;
	
}

float lotto::get_price()
{
	return price;
}

void lotto::set_name(string name) 
{
	this->name = name;
}

string lotto::get_name()
{
	return name;
}

lotto::lotto()
{
	city_tax = 0.05;
	county_tax = 0.08;
	lotto::set_name("No Game Name");
	lotto::set_price(1.00);
}

lotto::lotto(int type, string category, string name, float stock, float price)
{
	this->type = type;
	this->category = category;
	this->name = name;
	this->stock = stock;
	this->price = price;
}

lotto::~lotto()
{
	//Watch me as i become chrome destroyer of memory.
	//no pointers to dangle so w/e
}
