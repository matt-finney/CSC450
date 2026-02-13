#include <iostream>
#include <iomanip>
#include <conio.h>

// Standard namespace declaration
using namespace std;

// Main Function
int main()
{
     double myMoney = 1000.50;  //this should be printed out

     // Standard Output Statement
     cout << "Please be sure to correct all syntax errors in this program. "<<endl;
     cout << "I have corrected all errors for this program. " << endl;
     cout << "The total amount of money available is = $" << fixed << setprecision(2) << myMoney << endl;

     // Wait For Output Screen
     cout << "Press any key to continue...";
     _getch();

     // Main Function return Statement
     return 0;
}
