#include <iostream>
#include <limits>
using namespace std;

/*
    Matthew Finney
    CSC450 - Module 3
    
    Simple program that prompts the user for three integers,
    stores them in dynamic memory using pointers,
    and displays the values and their addresses.

    https://github.com/matt-finney/CSC450/
*/

// method to validate an integer input from the user
int readInt(const string& prompt) 
{
    int value;
    cout << prompt;
    
    // if input is not an integer, prompt user again
    while (!(cin >> value))
    {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear(); // clear the error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
    }
    return value;
}

int main() 
{
    // get three integers from the user
    int first_value, second_value, third_value;
    cout << "Enter three integer values:\n";
    first_value = readInt("First value: ");
    second_value = readInt("Second value: ");
    third_value = readInt("Third value: ");

    // make integer pointers to dynamic memory
    int* first_value_ptr = new int(first_value);
    int* second_value_ptr = new int(second_value);
    int* third_value_ptr = new int(third_value);

    // display variable contents and pointer info
    cout << "\n--- Variables ---\n";
    cout << "First value = " << first_value << "\t(address: " << &first_value << ")\n";
    cout << "Second value = " << second_value << "\t(address: " << &second_value << ")\n";
    cout << "Third value = " << third_value << "\t(address: " << &third_value << ")\n";

    cout << "\n--- Dynamic Memory via Pointers ---\n";
    cout << "first_value_ptr points to: " << first_value_ptr << " and has the value: " << *first_value_ptr << "\n";
    cout << "second_value_ptr points to: " << second_value_ptr << " and has the value: " << *second_value_ptr << "\n";
    cout << "third_value_ptr points to: " << third_value_ptr << " and has the value: " << *third_value_ptr << "\n";

    // free dynamic memory
    delete first_value_ptr;
    delete second_value_ptr;
    delete third_value_ptr;

    // avoid any potential dangling pointers
    first_value_ptr = nullptr;
    second_value_ptr = nullptr;
    third_value_ptr = nullptr;

    return 0;
}
