





#include <iostream>
#include <string>
#include <vector>

using namespace std;

//different types of products
#include "products.h"
#include "lotto.h"
#include "tobacco.h"
#include "non_perishable.h"

//runs the menu
#include "menu.h"

//Linked List Class
#include "point.h"

//file reading
#include <fstream>
#include <sstream>

//function declaration
void pull_file();


extern point* head;

int main()
{
    pull_file();


    menu * run = new menu();
    //do while?
    bool loop = true;
    while (loop == true) {
        run->print_menu();// prints menu and calls set input       
        try { run->set_input(); }
        catch (int) {
            cout << "The only error here is a out of bounds error on the users behalf." << endl;
            //code one is input out of range

        }
        // first check for exit code
        if (run->getinput() == 5) {//exit code
            //loop = false;//exits the loop, not anymore
            cout << " Have a great day, and thanks for using Tom Terminals!";
            break;// does this mitigate the while anyway? yep, whatever
        }

        //----------------SEARCH----------------SEARCH--------------SEARCH------------------
        if (run->getinput() == 4) {
            cout << "What do you want information on?\n1: A product by name?\n2: A product by type?\n3: A product by price ranghe?\n";
            cin.ignore();
            string string_input;
            //get input
            getline(cin, string_input);
            int input = stoi(string_input);
            //start if statements for different seraches
            if (input == 1) {
                cout << "Enter product name: ";
                string name;
                getline(cin, name);
                head->search(name);
            }
            else if (input == 2) {
                cout << "Enter a type to search by.\n1. Produce\n2. Dairy\n3. Bakery\n4. Deli\n5. Pantry\n"
                    << "6. Frozen\n7. Beverages\n8. Alchohol\n9. Tobacco\n10. Household\n11. Personal Care\n";
                string choice;
                getline(cin, choice);
                int category = stoi(choice);
                //i now have an int that correlates to a type of product in my database

                head->search(category);
            }
            else if (input == 3) {
                float min;
                float max;
                string line;
                cout << "Enter price range separated by a space: ";
                getline(cin, line);
                stringstream ss(line);
                //this is a cool thing to learn about
                if (!(ss >> min >> max)) {
                    cout << "Invalid input! Please enter two numbers separated by a space.\n";
                }
                else {
                    head->search(min, max);
                }
                

            }
            //----------------SEARCH----------------SEARCH--------------SEARCH------------------
        }

        //----------------REMOVE----------------REMOVE--------------REMOVE------------------
        if (run->getinput() == 3) {
            cout << "what would you like to remove from the store? \n";
            cin.ignore();
            string name;
            getline(cin, name);
            head->remove_product(name);
        }
        //----------------REMOVE----------------REMOVE--------------REMOVE------------------
        //----------------RESTOCK----------------RESTOCK--------------RESTOCK------------------
        if (run->getinput() == 2) {
            cout << "What would you like to Restock? " << endl;
            cin.ignore();
            string name;
            getline(cin, name);

            //get amount
            cout << "How much would you like to Restock? \n";
            float amount;
            cin >> amount;
            head->restock(name,amount);
        }
        //----------------RESTOCK----------------RESTOCK--------------RESTOCK------------------
        //----------------SELL----------------SELL--------------SELL------------------
        if (run->getinput() == 1) {

            //get item
            cout << "what would you like to sell? " << endl;
            cin.ignore();
            string n;
            getline(cin,n);

            //get amount
            cout << "how much would you like to sell? \n";
            float a;
            cin >> a;
        //----------------SELL----------------SELL--------------SELL------------------

            //----------------for testing delete print statements later-------------------
            //head->print_all();
            head->sell_item(n,a);
            //head->print_all();

        }
        
        //error code 1 is input out of range
    }
    
    
}
//------------------------END MAIN------------------------------------

void pull_file() {
    fstream file("database.csv");
    string line;
    if(!file.is_open()) {
        std::cerr << "Error: could not open database.csv\n";
        return;
    }
    

    while (getline(file,line)) {
        stringstream ss(line);

        string type_name;
        string name;
        //need to make strings
        string type_b;
        string stock_b;
        string price_b;
        //then convert from strings to int
        int type = 0;
        float stock = 0;
        float price = 0;

        getline(ss, type_name, ',');
        getline(ss, name, ',');
        getline(ss, type_b, ',');
        getline(ss, stock_b, ',');
        getline(ss, price_b, ',');

        type = stoi(type_b);
        stock = stof(stock_b);
        price = stof(price_b);

        //link?
        //point::build(type_name, name, type, stock, price); no longer used here

        products* p = nullptr;
        if (type == 9) {
            tobacco* t = new tobacco();
            t->set_name(name);
            t->set_price(price);
            t->set_stock(stock);
            t->set_type(type);
            t->set_category(type_name);
            //t->set_special_tax(value); nahh theyre all taxed the same so i'm leaving the tobacco and lott tax's inside the class as predefined
            p = t;
        }
        else if (type == 8) {
            lotto* l = new lotto();
            l->set_name(name);
            l->set_price(price);
            l->set_stock(stock);
            l->set_type(type);
            l->set_category(type_name);
            // l->set_city_tax(...); l->set_county_tax(...);
            p = l;
        }
        else {
            non_perishable* np = new non_perishable();//im running out of time everything else is non perishable
            np->set_name(name);
            np->set_price(price);
            np->set_stock(stock);
            np->set_type(type);
            np->set_category(type_name);
            p = np;
        }
    }
    file.close();
}
//temp notes: throw goes in the method the try and catch go elsewhere.
// as a single like if statement like if whatever conditions arent met throw {int error code}
 

// implement the database {sorta check}
// need to work on seeding prices from the parent class but that gets back
// into polymorphism
// need to make it do the array or vector or LL. which writes to the database.
// ugh i need to find a way to display all the products

//so the point::build() bullshit is where i am right now i cant figure it out and im tired and its 11:40
//fresh eyes tomorrow
