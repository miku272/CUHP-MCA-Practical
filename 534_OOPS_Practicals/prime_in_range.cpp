/*
Write a program to find and print all the prime numbers in a range given by the user
*/

#include <iostream>
#include <cmath>

bool is_prime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    int start = 0, end = 0;

    std::cout << "Enter the starting point: ";
    std::cin >> start;
    std::cout << "\n";

    std::cout << "Enter the ending point: ";
    std::cin >> end;
    std::cout << "\n\n";

    if (start < 0 || end < 0)
    {
        std::cout << "Range cannot be less than 0(Zero).";
        return -1;
    }

    std::cout << "The prime numbers are: ";
    if (start < end)
    {
        for (int i = start; i <= end; i++)
        {
            if (is_prime(i))
            {
                std::cout << i << " ";
            }
        }
    }
    else
    {
        for (int i = start; i >= end; i--)
        {
            if (is_prime(i))
            {
                std::cout << i << " ";
            }
        }
    }

    return 0;
}
