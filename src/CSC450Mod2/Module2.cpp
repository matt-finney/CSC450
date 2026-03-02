#include <iostream>
#include <string>

using namespace std;
/*
    Matthew Finney
    CSC450 - Module 2
    Simple program that prompts the user for two strings, concatenates them, and displays the results.
    Does this three times to show varying string lengths.

    https://github.com/matt-finney/CSC450/
*/

int main() 
{
    string first_string, second_string;

    // take input from the user three times
    for (int i = 0; i < 3; i++)
    {
        // Ask the user for two strings
        cout << "Enter the first string: ";
        getline(cin, first_string);

        cout << "Enter the second string: ";
        getline(cin, second_string);

        // Concatenate the strings
        string result = first_string + second_string;

        // Print the result
        cout << "Concatenated string: " << result << "\n" << endl;
    }

    return 0;
}
