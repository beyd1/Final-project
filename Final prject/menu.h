#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class menu
{
private:
	// i dont think this needs anything?
	int input = 0;// bleh it needs a user input, stupid users.
	void color(int);
public:
	void print_menu();
	void set_input();
	int getinput();
	menu();//do i need a constructor for this?

};

