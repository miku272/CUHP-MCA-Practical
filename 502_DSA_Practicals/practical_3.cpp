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

void merge(int arr[], int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start, a[100];

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            a[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            a[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        a[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end)
    {
        a[k] = arr[j];
        j++;
        k++;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = a[i];
    }
}

void merge_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[end]);

    return (i + 1);
}

void quick_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int partition_index = partition(arr, start, end);

        quick_sort(arr, start, partition_index - 1);
        quick_sort(arr, partition_index + 1, end);
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

    std::cout << "Choose one option:\n1. Merge sort.\n2. Quick sort.\n";

    std::cout << "Enter your choice: ";
    std::cin >> option;
    std::cout << "\n\n";

    switch (option)
    {
    case 1:
        std::cout << "Performing merge sort...\n";
        merge_sort(arr, 0, arr_length - 1);

        break;

    case 2:
        std::cout << "Performing quick sort...\n";
        quick_sort(arr, 0, arr_length - 1);

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
