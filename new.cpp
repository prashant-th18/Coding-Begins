#include <iostream>
using namespace std;
// Call by value
// When we want to write a swap function using call by value we will use *pointers*
void swap_value(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}
// Call By reference
// When we want to write a swap function using call by reference we will use *&*
void swap_reference(int& first, int &second)
{
    int c = first;
    first = second;
    second = c;
}
int main()
{
    int first = 10, second = 20;
    cout << "First is " << first << " & Second is " << second << endl;
    // Using Call By Value
    swap_value(&first, &second);
    cout << "First is " << first << " & Second is " << second << endl;



    first = 10; second = 20;
    cout << endl << endl << "First is " << first << " & Second is " << second << endl;
    // Using Call By Reference
    swap_reference(first, second);
    cout << "First is " << first << " & Second is " << second << endl;
    return 0;
}