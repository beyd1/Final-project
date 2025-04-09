
#include <iostream>
#include "products.h"
#include "lotto.h"
#include "tobacco.h"
#include "menu.h"


using namespace std;



int main()
{
    menu run;
    //do while?
    bool loop = true;
    while (loop == true) {
        run.print_menu();

        if (run.getinput() == 5) {//exit code
            loop = false;//exits the loop
        }
    }
    
    
}
/*made the classes ALL of them please dont add more work for yourself
 you have to make isaacs shit tomorrow.*/ 
// Put menu in a loop {check}
// finish polymorphism
// implement the database
// need to work on seeting prices from the parent class but that gets back
// into polymorphism
// need to make it do the array or vector or LL. which writes to the database.
