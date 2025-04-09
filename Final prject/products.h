#pragma once
#include <string.h>
#include <string>
using namespace std;

//this is a virtual class
class products
{
private:
	float price;
	string name;
	float stock;
public:
	void virtual set_price(float);
	float virtual get_price();

	void virtual set_name(string);
	string virtual get_name();


	void add_product(int);// name , price 

};

