#include <iostream>

class String
{
private:
    int str_size;
    char *str;

public:
    String()
    {
        this->str_size = 20;
        this->str = new char[this->str_size];
    }

    String(int str_size)
    {
        this->str_size = str_size;
        this->str = new char[this->str_size];
    }

    String(int size, char *str)
    {
        this->str_size = size;
        this->str = str;
    }

    void set_string()
    {
        std::cout << "Enter your string (Max length " << this->str_size << "): ";
        std::cin.getline(this->str, this->str_size);
    }

    char get_char(int index)
    {
        return this->str[index];
    }

    int get_size()
    {
        return this->str_size;
    }

    String operator+(String s)
    {
        int new_size = (this->str_size + s.get_size()) - 1; // Removing one '\0' but keeping the another '\0'
        char *new_str = new char[new_size];

        int new_str_counter = 0;
        int i = 0;
        while (this->str[i] != '\0')
        {
            new_str[new_str_counter] = this->str[i];
            new_str_counter++;
            i++;
        }

        i = 0;

        while (s.get_char(i) != '\0')
        {
            new_str[new_str_counter] = s.get_char(i);
            new_str_counter++;
            i++;
        }

        new_str[new_str_counter] = '\0';

        String new_string(new_size, new_str);

        return new_string;
    }

    void display()
    {
        std::cout << this->str;
    }
};

int main(int argc, char const *argv[])
{
    String s1, s2, s3;

    s1.set_string();
    s2.set_string();

    s3 = s1 + s2;

    s3.display();

    std::cout << s1.get_size() << "\n" << s2.get_size() << "\n" << s3.get_size();

    return 0;
}
