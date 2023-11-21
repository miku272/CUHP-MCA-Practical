/*
Write a program using template to sort a list of elements. Give users the option to perform sorting using Counting sort and Radix sort.
*/

#include <iostream>

void counting_sort(int arr[], int arr_length)
{
    int max = arr[0];

    // Find the max array in the array
    for (int i = 1; i < arr_length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Create new 'output' and 'count' array dynamically
    int *output = new int[arr_length];
    int *count = new int[max + 1];

    // Initialize the count array with zeros
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Store the frequency of each element from 'arr' in 'count'
    for (int i = 0; i < arr_length; i++)
    {
        count[arr[i]]++;
    }

    // Store the cummulative frequency of each array
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = arr_length - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];

        count[arr[i]]--;
    }

    // Copy the sorted element into the original array
    for (int i = 0; i < arr_length; i++)
    {
        arr[i] = output[i];
    }

    // Deallocate the memory of 'count' and 'output'
    delete[] count;
    delete[] output;
}

void counting_sort(int arr[], int arr_length, int place)
{
    int max = 10;

    // Find the max value from the 'arr'
    // for (int i = 1; i < arr_length; i++)
    // {
    //     if (arr[i] > max)
    //     {
    //         max = arr[i];
    //     }
    // }

    // Create new 'output' and 'count' array dynamically
    int *output = new int[arr_length];
    int *count = new int[max];

    // Initialize count with zeros
    for (int i = 0; i < max; i++)
    {
        count[i] = 0;
    }

    // Calculate frequenty of elements in arr
    for (int i = 0; i < arr_length; i++)
    {
        count[(arr[i] / place) % 10]++;
    }

    // Calculate cummulative frequency of elements in arr
    for (int i = 1; i < max; i++)
    {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    for (int i = arr_length - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];

        count[(arr[i] / place) % 10]--;
    }

    // Copying the output in original array
    for (int i = 0; i < arr_length; i++)
    {
        arr[i] = output[i];
    }

    // Deallocate the memory of 'count' and 'output'
    delete[] output;
    delete[] count;
}

void radix_sort(int arr[], int arr_length)
{
    int max = arr[0];

    // Find maximum element from 'arr'
    for (int i = 0; i < arr_length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Appying counting sort to sort element based on place value;
    for (int place = 1; max / place > 0; place *= 10)
    {
        counting_sort(arr, arr_length, place);
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

    std::cout << "Choose one option:\n1. Counting sort.\n2. Radix sort.\n";

    std::cout << "Enter your choice: ";
    std::cin >> option;
    std::cout << "\n\n";

    switch (option)
    {
    case 1:
        std::cout << "Performing Counting sort...\n";
        counting_sort(arr, arr_length);

        break;

    case 2:
        std::cout << "Performing Radix sort...\n";
        // radix_sort(arr, 0, arr_length - 1);

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
