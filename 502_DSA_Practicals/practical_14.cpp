#include <iostream>
using namespace std;

// Function to calculate factorial using iteration
int factorialIterative(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// Function to calculate factorial using recursion
int factorialRecursive(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Calculate factorial using iteration
    int factorialIter = factorialIterative(num);
    cout << "Factorial using iteration: " << factorialIter << endl;

    // Calculate factorial using recursion
    int factorialRec = factorialRecursive(num);
    cout << "Factorial using recursion: " << factorialRec << endl;

    return 0;
}
