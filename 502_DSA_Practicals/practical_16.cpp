#include <iostream>
using namespace std;

int gcdRecursive(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcdRecursive(b, a % b);
}

int gcdNonRecursive(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "GCD of " << num1 << " and " << num2 << " using recursion is: " << gcdRecursive(num1, num2) << endl;
    cout << "GCD of " << num1 << " and " << num2 << " without recursion is: " << gcdNonRecursive(num1, num2) << endl;
    return 0;
}
