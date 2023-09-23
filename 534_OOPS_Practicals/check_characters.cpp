#include <iostream>

int main(int argc, char const *argv[])
{
    char ch;

    std::cout << "Enter any character(Subsequent characters will not be considered): ";
    std::cin >> ch;
    std::cout << "\n\n";

    int ascii_val = (int)ch;

    if ((ascii_val >= 0 && ascii_val <= 64) || (ascii_val >= 91 && ascii_val <= 96))
    {
        std::cout << "Entered character is symbol";
    }
    else if (ascii_val == 65 || ascii_val == 97 || ascii_val == 69 || ascii_val == 101 || ascii_val == 73 || ascii_val == 105 || ascii_val == 79 || ascii_val == 111 || ascii_val == 85 || ascii_val == 117)
    {
        std::cout << "Entered character is vowel";
    }
    else
    {
        std::cout << "Entered character is consonant";
    }

    return 0;
}
