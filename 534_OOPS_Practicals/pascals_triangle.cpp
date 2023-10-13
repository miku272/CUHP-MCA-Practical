#include <iostream>

int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }

    return num * factorial(num - 1);
}

int combination(int n, int r)
{
    return factorial(n) / (factorial(r) * (factorial(n - r)));
}

void pascals_triangle(int rows)
{
    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j <= rows - i; j++) {
            std::cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            std::cout << "  " << combination(i, j);
        }
        std::cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    int rows = 0;

    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "\n\n";

    pascals_triangle(rows);

    return 0;
}
