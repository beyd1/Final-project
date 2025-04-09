#include "tobacco.h"

void tobacco::set_price(float price)
{
	price = price * (1 + (1 * tax));
	this->price = price;// do i call the parent function here?
	
}

float tobacco::get_price()
{
	return price;
}
