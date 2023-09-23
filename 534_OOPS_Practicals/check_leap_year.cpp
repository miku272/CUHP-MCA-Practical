#include <iostream>

int main(int argc, char const *argv[])
{
    int year = 0;

    std::cout << "Enter a year between 1 to 9999: ";
    std::cin >> year;

    if (year < 1 && year > 9999)
    {
        std::cout << "You entered wrong year...";
        return -1;
    }

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        std::cout << year << " is a leap year.";
    }
    else
    {
        std::cout << year << " is NOT a leap year";
    }

    return 0;
}
