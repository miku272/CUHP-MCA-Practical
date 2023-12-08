#include <iostream>

// Function to calculate Fibonacci series using recursion
int fibonacciRecursion(int n)
{
    if (n <= 1)
        return n;
    return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

// Function to calculate Fibonacci series using iteration
int fibonacciIteration(int n)
{
    if (n <= 1)
        return n;

    int fib = 0;
    int prev1 = 0;
    int prev2 = 1;

    for (int i = 2; i <= n; i++)
    {
        fib = prev1 + prev2;
        prev1 = prev2;
        prev2 = fib;
    }

    return fib;
}

int main()
{
    int n;
    std::cout << "Enter the number of terms: ";
    std::cin >> n;

    std::cout << "Fibonacci series using recursion: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << fibonacciRecursion(i) << " ";
    }

    std::cout << "\nFibonacci series using iteration: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << fibonacciIteration(i) << " ";
    }

    return 0;
}
