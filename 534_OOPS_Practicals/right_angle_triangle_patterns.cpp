#include <iostream>

void triangle_pattern_1(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}

void triangle_pattern_2(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= rows - i + 1; j++)
        {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}

void triangle_pattern_3(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= rows - i; j++)
        {
            std::cout << "  ";
        }

        for (int j = 1; j <= i; j++)
        {
            std::cout << " *";
        }

        std::cout << "\n";
    }
}

void triangle_pattern_4(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = rows; j >= rows - i + 1; j--)
        {
            std::cout << "  ";
        }

        for (int j = 1; j <= rows - i + 1; j++)
        {
            std::cout << "* ";
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

    // triangle_pattern_1(rows);
    // triangle_pattern_2(rows);
    // triangle_pattern_3(rows);
    triangle_pattern_4(rows);

    return 0;
}
