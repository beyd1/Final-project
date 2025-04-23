#include "non_perishable.h"

non_perishable::non_perishable()
{
	price = 0.0f;
	stock = 0.0f;
	type = 0;
	non_perishable::set_name("No Game Name");
	non_perishable::set_price(1.00);
}

non_perishable::non_perishable(int type, string category, string name, float stock, float price)
{
	this->type = type;
	this->category = category;
	this->name = name;
	this->stock = stock;
	this->price = price;
}
