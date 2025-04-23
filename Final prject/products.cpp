#include "products.h"


products::products()
{
	price = 0.0;
	name = "noname";
	stock = 0.0;
}

products::products(int type, string category, string name, float stock, float price)
{
	this->type = type;
	this->category = category;
	this->name = name;
	this->stock = stock;
	this->price = price;

}

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



/*void products::add_product(float price, string name, float stock)//does it need input?
{
	this->price = price;
	this->name = name;
	this->stock = stock;

	//no this is just going to access a vector and add an object
	//this might not be used at all
}*/
