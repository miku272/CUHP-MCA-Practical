/*
Write a program using templates to sort a list of elements. Give user the option to perform sorting using insertion sort, bubble sort, selection sort.
*/

#include <iostream>

void swap(int *val1, int *val2)
{
    int temp = *val1;

    *val1 = *val2;
    *val2 = temp;
}

void bubble_sort(int arr[], int arr_length)
{
    bool isSwapped = false;

    for (int i = 0; i < arr_length - 1; i++)
    {
        isSwapped = false;

        for (int j = 0; j < arr_length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSwapped = true;
            }
        }

        if (!isSwapped)
        {
            break;
        }
    }
}

void selection_sort(int arr[], int arr_length)
{
    int smallest_index = 0;

    for (int i = 0; i < arr_length - 1; i++)
    {
        smallest_index = i;

        for (int j = i + 1; j < arr_length; j++)
        {
            if (arr[j] < arr[smallest_index])
            {
                smallest_index = j;
            }
        }

        if (smallest_index != i)
        {
            swap(&arr[smallest_index], &arr[i]);
        }
    }
}

void insertion_sort(int arr[], int arr_length)
{
    int current_element = 0, previous_index = 0;

    for (int i = 1; i < arr_length; i++)
    {
        current_element = arr[i];
        previous_index = i - 1;

        // Finding out the correct position to insert
        while (previous_index >= 0 && arr[previous_index] > current_element)
        {
            arr[previous_index + 1] = arr[previous_index];
            previous_index--;
        }

        // Insertion
        arr[previous_index + 1] = current_element;
    }
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

    std::cout << "Choose one option:\n1. Insertion sort.\n2. Bubble sort.\n3. Selection sort.\n";

    std::cout << "Enter your choice: ";
    std::cin >> option;
    std::cout << "\n\n";

    switch (option)
    {
    case 1:
        std::cout << "Performing insertion sort...\n";
        insertion_sort(arr, arr_length);

        break;

    case 2:
        std::cout << "Performing bubble sort...\n";
        bubble_sort(arr, arr_length);

        break;

    case 3:
        std::cout << "Performing selection sort...\n";
        selection_sort(arr, arr_length);

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
