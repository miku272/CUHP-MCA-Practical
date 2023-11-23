#include <iostream>
#include <string>

class StudMarks
{
private:
    int marks;
    std::string name;

public:
    StudMarks()
    {
        this->marks = 50;
        this->name = "Naresh";
    }

    void operator++()
    {
        this->marks++;
    }

    void operator--()
    {
        this->marks--;
    }

    void display() {
        std::cout << "Name: " << this->name << "\nMarks: " << this->marks;
    }
};

int main(int argc, char const *argv[])
{
    StudMarks s;
    system("cls");

    std::cout << "\n----------- Initial -----------\n";
    s.display();

    std::cout << "\n---------- Increment ----------\n";
    ++s;
    s.display();
    --s;

    std::cout << "\n---------- Decrement ----------\n";
    --s;
    s.display();

    return 0;
}
