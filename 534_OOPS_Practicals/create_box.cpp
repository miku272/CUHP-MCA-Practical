#include <iostream>

int main(int argc, char const *argv[])
{
    int length = 30, breadth = 6/*, area = length * breadth*/;

    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "\n";

    std::cout << "Enter breadth: ";
    std::cin >> breadth;
    std::cout << "\n\n";

    // area = length * breadth;

    for (int i = 1; i <= breadth; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            if (i == 1 || i == breadth || j == 1 || j == length)
            {

                std::cout << "*";
            }
            else
            {
                if ((i == (breadth / 2)) && (j == (length / 2)))
                {
                    // std::cout << "\u2190";
                    std::cout << "-";
                }
                else if ((i == (breadth / 2)) && (j == (length / 2) + 1))
                {
                    std::cout << ">";
                }
                else
                {

                    std::cout << " ";
                }
            }
        }

        std::cout << "\n";
    }

    return 0;
}
