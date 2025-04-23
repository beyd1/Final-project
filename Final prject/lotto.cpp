#include "lotto.h"


lotto::lotto()
{
	price = 0.0f;
	stock = 0.0f;
	type = 0;
	city_tax = 0.05f;
	county_tax = 0.08f;
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
	city_tax = 0.05f;
	county_tax = 0.08f;
}

lotto::~lotto()
{
	//Watch me as i become chrome destroyer of memory.
	//no pointers to dangle so w/e
}

float lotto::compute_price()
{

	return products::compute_price() * (city_tax + county_tax) + products::compute_price();
}
