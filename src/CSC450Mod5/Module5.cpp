#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

/*
    Matthew Finney
    CSC450 - Module 5
    
    Simple program that prompts the user for input,
    appends it to a file. Then reads the file to reverse it and writes that into a new file.
    
    https://github.com/matt-finney/CSC450/
*/

int main() 
{
    string user_input;
    string filename = "CSC450_CT5_mod5.txt";

    // Get input from user
    cout << "Enter text to append to the file: ";
    getline(cin, user_input);

    // Append user input to the original file
    ofstream out_file(filename, ios::app);
    // Check if the file opened successfully
    // if there was an error opening the file, print an error message and exit
    if (!out_file) 
    {
        cout << "Error opening " << filename << " for appending." << endl;
        return 1;
    }

    // Write the user input to the file and close it
    out_file << user_input << "\n";
    out_file.close();

    // Read all of the contents from the original file
    ifstream in_file(filename);
    // Check if the file opened successfully
    // if there was an error opening the file, print an error message and exit
    if (!in_file) 
    {
        cout << "Error opening " << filename << " for reading." << endl;
        return 1;
    }

    // Read the entire file content into a string
    string content((istreambuf_iterator<char>(in_file)),
                   istreambuf_iterator<char>());
    in_file.close();

    // Reverse all characters
    reverse(content.begin(), content.end());

    // Write the reversed contents into a new file
    // and if there was an error opening the file, print an error message and exit
    string reverse_filename = "CSC450-mod5-reverse.txt";
    ofstream reverse_file(reverse_filename);
    if (!reverse_file) {
        cout << "Error opening " << reverse_filename << " for writing." << endl;
        return 1;
    }

    // Write the reversed content to the new file and close it
    reverse_file << content;
    reverse_file.close();

    // Print success messages for readability
    cout << "Input appended successfully." << endl;
    cout << "Reversed file created successfully." << endl;

    return 0;
}