#include <iostream>

int main(int argc, char const *argv[])
{
    int units = 0;

    std::cout << "Enter no of units used: ";
    std::cin >> units;
    std::cout << "\n";

    if (units < 0)
    {
        std::cout << "Please enter valid units.";
        return -1;
    }

    if (units >= 0 && units <= 100)
    {
        std::cout << "Your total electricity bill is: " << units * 0.25 << " rupees";
    }
    else if (units >= 101 && units <= 200)
    {
        std::cout << "Your total electricity bill is: " << units * 0.50 << " rupees";
    }
    else if (units >= 201 && units <= 300)
    {
        std::cout << "Your total electricity bill is: " << units * 0.75 << " rupees";
    }
    else if (units >= 301 && units <= 400)
    {
        std::cout << "Your total electricity bill is: " << units * 1.25 << " rupees";
    }
    else if (units >= 401 && units <= 600)
    {
        std::cout << "Your total electricity bill is: " << units * 1.75 << " rupees";
    }
    else
    {
        std::cout << "Your total electricity bill is: " << units * 2.50 << " rupees";
    }

    return 0;
}
