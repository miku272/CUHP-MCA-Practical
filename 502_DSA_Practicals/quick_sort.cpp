#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int i = start + 1;
    int j = end;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);

    swap(&arr[start], &arr[j]);

    return j;
}

void quick_sort(int arr[], int start, int end)
{
    int partition_index = 0;

    if (start < end)
    {
        partition_index = partition(arr, start, end);

        quick_sort(arr, start, partition_index - 1);
        quick_sort(arr, partition_index + 1, end);
    }
}

void print_arr(int arr[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        std::cout << arr[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 5, 1, 10, 8};
    int arr_length = sizeof(arr) / sizeof(arr[0]);

    print_arr(arr, arr_length);
    std::cout << "\n\n";

    quick_sort(arr, 0, arr_length - 1);

    print_arr(arr, arr_length);

    return 0;
}
