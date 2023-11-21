#include <iostream>
#include <string>

class Student
{
private:
    int age;
    int pocket_money;

protected:
    int protected_var;

public:
    std::string name;

    Student(std::string name, int age, int pocket_money, int protected_var)
    {
        this->name = name;
        this->age = age;
        this->pocket_money = pocket_money;
        this->protected_var = protected_var;
    }

    int get_pocket_money(std::string name)
    {
        if (name == "Naresh")
        {
            return this->pocket_money;
        }
        else
        {
            return -1;
        }
    }
};

int main(int argc, char const *argv[])
{
    Student *stud = new Student("Gaurav", 24, 250000, 10);

    // std::cout << stud->name;
    // std::cout << stud->pocket_money;

    // std::cout << stud->get_pocket_money("dfgddfh");

    delete stud;
    return 0;
}
