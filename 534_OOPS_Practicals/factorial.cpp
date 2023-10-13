#include <iostream>

int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }

    return num * factorial(num - 1);
}

int main(int argc, char const *argv[])
{
    int num = 0;

    std::cout << "Enter the number you want to find the factorial of: ";
    std::cin >> num;
    std::cout << "\n\n";

    std::cout << "The factorial of " << num << " is " << factorial(num);

    return 0;
}
