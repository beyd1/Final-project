#include "tobacco.h"





tobacco::tobacco()
{
	price = 0.0f;
	stock = 0.0f;
	type = 0;
	tax = 0.05f;
	tobacco::set_name("No Game Name");
	tobacco::set_price(1.00);
}

tobacco::tobacco(int type, string category, string name, float stock, float price)
{
	this->type = type;
	this->category = category;
	this->name = name;
	this->stock = stock;
	this->price = price;
	tax = 0.05f;

}

tobacco::~tobacco()
{
	//no pointers to deconstruct.
}
float tobacco::compute_price()
{

	return products::compute_price() * (tax) + products::compute_price();
}
