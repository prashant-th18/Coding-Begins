#include <iostream>
#include <vector>
#include "Mystring.h"

//imppppppppppp!!!!!!!!!! line no 20 is like this is a test will be first stored in a temp value using overloaded costructor then 
// copy assignment will be called for it!!!!!




using namespace std;

int main() {
    Mystring a {"Hello"};                // overloaded constructor
    Mystring b;                             // no-args contructor
    b = a;                                      // copy assignment 
                                                  // b.operator=(a)
    b = "This is a test";                 // b.operator=("This is a test");
  
  return 0;
}