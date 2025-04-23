#include "tobacco.h"

void tobacco::set_price(float price)
{
	price = price * (1 + (1 * tax));
	this->price = price;
	
}

float tobacco::get_price()
{
	return price;
}

tobacco::tobacco()
{
	
	tobacco::set_name("No Brand Set");
	tobacco::set_price(1);

}

tobacco::tobacco(int type, string category, string name, float stock, float price)
{
	this->type = type;
	this->category = category;
	this->name = name;
	this->stock = stock;
	this->price = price;

}

tobacco::~tobacco()
{
	//no pointers to deconstruct.
}
