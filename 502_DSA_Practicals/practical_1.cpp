/*
Write a program to search an element from a list. Give user the option to perform Linear or binary search
*/

#include <iostream>

int linearSearch(int values[], int start, int end, int element)
{
    for (int i = 0; i < end; i++)
    {
        if (values[i] == element)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int values[], int start, int end, int element)
{
    int mid = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (values[mid] == element)
        {
            return mid;
        }

        if (values[mid] < element)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int values[] = {2, 4, 6, 8, 10, 12, 14};
    int element = 20;
    int values_length = sizeof(values) / sizeof(values[0]);
    int option = 0;
    int result = -1;

    std::cout << "1. Perform linear search.\n2. Perform binary search.\n\n";

    std::cout << "Enter your choice: ";
    std::cin >> option;
    std::cout << "\n\n";

    switch (option)
    {
    case 1:
        result = linearSearch(values, 0, values_length, element);

        std::cout << "Performing linear search...\n\n";
        if (result == -1)
        {
            std::cout << "Element " << element << " NOT FOUND in the array";
        }
        else
        {
            std::cout << "Element " << element << " FOUND at index: " << result;
        }

        break;

    case 2:
        result = binarySearch(values, 0, values_length, element);

        std::cout << "Performing binary search...\n\n";
        if (result == -1)
        {
            std::cout << "Element " << element << " NOT FOUND in the array";
        }
        else
        {
            std::cout << "Element " << element << " FOUND at index: " << result;
        }

        break;

    default:
        std::cout << "You chose an incorrect option. Please run the program again";
    }

    return 0;
}
