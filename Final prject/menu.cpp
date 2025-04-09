#include "menu.h"



void menu::color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void menu::print_menu()
{
	cout << "Hello, and welcome to Tom Terminals! Your exclusive source for things that tom is selling you from the terminal!\n";
	cout << "What would you like to do?\n";
	color(4); cout << "(1) Sell\n"; //change text color to red and print sell
	color(2); cout << "(2) Restock\n"; // color green  print restock
	color(1); cout << "(3) Remove\n"; // color blue print remove
	color(6); cout << "(4) Search\n"; // yellow search
	color(5); cout << "(5) Exit\n"; // magenta exit
	//DO NOT REMOVE THIS LINE
	color(7);// change back to default color
	//DO NOT REMOVE THIS LINE
	//this is very irresponsible, it's permanant.

	cout << "Your choice: ";
	cin >> input;// same line
	
	
	
}

void menu::set_input(int input)
{
	this->input = input;
}

int menu::getinput()
{
	return input;
}

menu::menu()
{
	//no constructor
}
