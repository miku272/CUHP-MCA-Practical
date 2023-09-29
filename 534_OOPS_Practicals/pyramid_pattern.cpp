#include <iostream>

int main(int argc, char const *argv[])
{
    int rows = 0;

    std::cout << "Enter number of rows: ";
    std::cin >> rows;

    system("cls");

    for (int i = 1; i <= rows; i++)
    {
        int j = 1;
        for (j = 1; j <= rows - i; j++)
        {
            std::cout << " ";
        }

        while (j <= rows)
        {
            std::cout << "* ";
            j++;
        }

        std::cout << "\n";
    }

    return 0;
}
