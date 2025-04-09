#include "products.h"

void products::set_price(float price)
{
	this->price = price;
}

float products::get_price()
{
	return price;
}

void products::set_name(string name)
{
	this->name = name;
}

string products::get_name()
{
	return name;
}

void products::add_product(int)//does it need input?
{
}
