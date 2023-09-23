/*
Write a program using templates to sort a list of elements. Give user the option to perform sorting using Merge sort and Quick sort.
*/

#include <iostream>

void swap(int *val1, int *val2)
{
    int temp = *val1;

    *val1 = *val2;
    *val2 = temp;
}

void merge_sort(int arr[], int arr_length)
{
}

void quick_sort(int arr[], int arr_length)
{
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 1, 4, 2, 8};
    int arr_length = sizeof(arr) / sizeof(arr[0]);
    int option = 0;

    std::cout << "Unsorted array: ";
    for (int i = 0; i < arr_length; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Choose one option:\n1. Merge sort.\n2. Quick sort.\n";

    std::cout << "Enter your choice: ";
    std::cin >> option;
    std::cout << "\n\n";

    switch (option)
    {
    case 1:
        std::cout << "Performing merge sort...\n";
        merge_sort(arr, arr_length);

        break;

    case 2:
        std::cout << "Performing quick sort...\n";
        quick_sort(arr, arr_length);

        break;

    default:
        std::cout << "You have entered the wrong choice. Please run the program again...";
        return -1;
    }

    std::cout << "Sorted array: ";
    for (int i = 0; i < arr_length; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
