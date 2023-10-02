/*
Write a program to find and print all the armstrong numbers in a range given by the user
*/

#include <iostream>
#include <cmath>

bool is_armstrong(int num)
{
    int temp = num, sum = 0;

    while (temp > 0)
    {
        sum += pow(temp % 10, 3);

        temp = temp / 10;
    }

    if (sum == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int start = 0, end = 0;

    std::cout << "Enter starting point: ";
    std::cin >> start;
    std::cout << "\n";

    std::cout << "Enter ending point: ";
    std::cin >> end;
    std::cout << "\n\n";

    if ((start < 100 || start > 999) || (end < 100 || end > 999))
    {
        std::cout << "Rnage cannot be less than 100 or greater than 999.";

        return -1;
    }

    std::cout << "The armstrong numbers are: ";
    if (start < end)
    {
        for (int i = start; i <= end; i++)
        {
            if (is_armstrong(i))
            {
                std::cout << i << " ";
            }
        }
    }
    else
    {
        for (int i = start; i >= end; i--)
        {
            if (is_armstrong(i))
            {
                std::cout << i << " ";
            }
        }
    }

    return 0;
}
