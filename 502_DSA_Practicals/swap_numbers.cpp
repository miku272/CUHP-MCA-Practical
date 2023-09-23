/*
Write a function to swap two numbers.
*/

#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int main(int argc, char const *argv[])
{
    int x = 10, y = 20;

    std::cout << "Before swapping :-   x: " << x << ", y: " << y << "\n\n";

    swap(&x, &y);

    std::cout << "After swapping :-   x: " << x << ", y: " << y;

    return 0;
}
