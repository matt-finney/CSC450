#include <iostream>

int main()
{
    int iNo;
    double dblPrice, dblTotal;

    std::cout << "Enter price per unit: ";
    std::cin >> dblPrice;
    std::cout << "Enter quantities: ";
    std::cin >> iNo;
    dblTotal = iNo * dblPrice;
    std::cout << "Total price is: " << dblTotal << std::endl;

    return 0;

}