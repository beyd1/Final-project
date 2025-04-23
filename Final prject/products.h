#pragma once
#include <string.h>
#include <string>

#include "point.h"

using namespace std;

//this is a virtual class
class products
{
private:
	string category;
	string name = "no name";
	float stock = 0.0;
	float price = 0.0;
	int type;


public:
	products();
	products(int, string, string, float, float);
	virtual void set_price(float);
	virtual float  get_price();

	virtual void set_name(string);
	virtual string get_name();




	/*void add_product(float, string, float);// name , price*/

};

