#include "lotto.h"

void lotto::set_price(float price)
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
