#include "point.h"
point* head = nullptr;

point::point()
{
	//data
	type = 0;
	stock = 0.0;
	price = 0.0;
	name = "name";
	type_name = "type_name"; //uhh for future reference typename is a keyword so this is probably bad practice
	//linker
	next = nullptr;
}

point::point(string tn, string n, int t, float s, float p)
{
	//data
	type_name = tn;
	name = n;
	type = t;
	stock = s;
	price = p;
	//linker
	next = nullptr;
}


void point::insert_at_start()
{
	this->next = head;
	head = this;
}

void point::build(string tn,string n ,int t,float s,float p)
{
	point* new_node = new point(tn, n, t, s, p);//typename,name,type,stock,price
	new_node->insert_at_start();
}

point* point::get_next()
{
	return next;
}

void point::search(const string input)
{

	point* here = head;

	while (here != nullptr) {
		if (here->name == input) {
			cout << "Found Item: " << here->name;
			cout << "Type: " << here->type_name;
			cout << " Stock: " << here->stock << " remaining." << endl;
			return;
		}
		here = here->next;
	}
	cout << " No such product in the database. Please check spelling/capitalization and try again." << endl;

}

void point::search(int type)//for types gonna have to pull a string maybe? and convert that to and int to feed to the method
{
	bool found = false;
	point* here = head;

	while (here != nullptr) {
		if (here->type == type) {
			//found an item
			found = true;
			//print every item we find
			cout << "Found Item: " << here->name;
			cout << " of type " << here->type_name;
			cout << " Stock: " << here->stock << " remaining." << endl; // need to add more! maybe its just 3 if statements? depending on type that im pulling?
			
		}
		here = here->next;
	}
	if(!found)
		cout << " No such type of product in the database. Please check and try again." << endl;

}

void point::search(float min, float max)//for price ranges
{
	bool found = false;
	point* here = head;

	while (here != nullptr) {//traverse
		if (here->price >= min and here->price <= max) {
			cout << here->name << endl;
			cout << "Type: " << here->type_name << endl;
			cout << "Stock: " << here->stock << endl;
			cout << "Price: " << here->price << endl;
			found = true;// flags for second if statement

		}
		here = here->next;
	}
	if (!found) {
		cout << "No products in the price range $" << min << " to $" << max << "!\n";
	}
	
	
}

void point::print_all()
{
	point* here = head;
	if (here == nullptr) {
		cout << "THE STORE HAS NO PRODUCTS!!!!!! \n";
		return;
	}
	while (here != nullptr) {
		cout << "Name: " << here->name;
		cout << "\nType: " << here->type;
		cout << "\nStock: " << here->stock;
		cout << "\nPrice: " << here->price;

		here = here->next;
		if (here != nullptr)
			cout << "\n ---Next Item---\n\n";

	}
	cout << "\n";

	
}

void point::restock(string name, float amount)
{
	point* here = head;

	while (here != nullptr) {
		if (here->name == name) {
			//-> Increment the stock count
			here->stock = here->stock + amount;
			//print a statement to confirm restocking of item
			cout << "Restocked " << amount << " Units of " << here->name << endl;

			return;

		}
		here = here->next;

	}
}

void point::remove_product(string remove_name)
{
	//empty list
	if (!head) {
		cout << "Store is empty! Try restocking!\n ";
		return;
	}

	//one item list
	if (head->name == remove_name) {
		point* to_del = head;
		head = head->next;
		delete to_del;
		cout << "Removed " << remove_name << " from the store.\n";
		return;
	}

	//other size lists
	point* here = head;
	while (here->next and here->next->name != remove_name) {
		here = here->next;
	}
	if (here->next) {//only executes if it finds the right node
		//here->next is the node i want
		point* to_del = here->next;// this is what we delete in two steps
		point* temp = to_del->next;// here->next->next
		delete to_del;// delete old thing //whatever im tired
		here->next = temp;// new link
		cout << "Removed " << remove_name << " from the store\n";
	}
	else {
		cout << "Item " << remove_name << "is not found in database.\n";
	}
}





void point::sell_item(string name, float amount)
{
	point* here = head;

	while (here != nullptr) {
		if (here->name == name) {
			//->decrement the stock count
			//-> if we get to billing we can add the total to a bill class
			if (here->stock > amount) {
				here->stock = here->stock - amount;
				//print a statement to confirm selling of item
				cout << "Sold " << amount << " Units of " << here->name << endl;
				/*cout << "at a price of " << here->compute_price();*/
				return;
			}
			else {
				cout << "Not enough stock of " << here->name << " to sell " << amount << " units";
				return;
			}
			
		}
		here = here->next;

	}
}

string point::get_type_name()
{
	//uhhh this is gonna be a later thing its a whole lot of if statements maybe a switch, whatever.
	return type_name;
}

string point::get_name()
{
	return name;
}

int point::get_type()
{
	return type;
}

float point::get_stock()
{
	return stock;
}


point::~point()//lets deallocate memory if we need to
{
	if (!dead) {
		while (head != nullptr) {
			point* temp = head;
			head = head->get_next();
			delete temp;
		}
		dead = true;
	}
}

//1. Done
//2. Done 
//3. Done