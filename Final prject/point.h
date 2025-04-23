#pragma once
#include <iostream>
#include <string>

#include "products.h"
using namespace std;

class point
{
private:
	string type_name;
	string name;
	int type;
	float stock;
	float price;

	point* next;

	//for the deststructor cause i think this can blow up if im not carefull.
	bool dead = false;

public:
	point();
	point(string tn, string n, int t, float s, float p);

	~point();

	void insert_at_start();
	//^^relies on
	static void build(string,string,int,float,float);
	point* get_next();

	void search(string);//working on it!
	void search(int);
	void search(float, float);
	void print_all();

	void restock(string, float);
	void remove_product(string);
	void sell_item(string, float);


	string get_type_name();
	string get_name();
	int get_type();
	float get_stock();



};

