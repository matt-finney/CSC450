#include <iostream>
#include <limits>
using namespace std;

/*
    Matthew Finney
    CSC450 - Module 1
    Simple program that prompts the user for their name and address, then displays the results.

    https://github.com/matt-finney/CSC450/
*/

int main()
{
    // get first name
    string first_name;
    cout << "What is your first name? ";
    cin >> first_name;
    // get last name
    string last_name;
    cout << "What is your last name? ";
    cin >> last_name;

    // consume leftover newline before using getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // get street address
    string street_address;
    cout << "What is your street address? ";
    getline(cin, street_address); // use getline to allow for spaces

    // get city
    string city;
    cout << "What city do you live in? ";
    getline(cin, city);
        
    // get zip code
    int zip_code;
    cout << "What is your zip code? ";
    cin >> zip_code;

    // display results
    cout << "Your name is " << first_name << " " << last_name << "\n";
    cout << "Your address is " << street_address << ", " << city << ", " << zip_code << endl;

    return 0;
}