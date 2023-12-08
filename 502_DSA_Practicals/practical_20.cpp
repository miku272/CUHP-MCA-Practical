#include <iostream>
using namespace std;

class Symmetric
{
private:
    int *Arr;
    int size;

public:
    Symmetric(int no = 10)
    {
        this->size = no;
        Arr = new int[size * (size + 1) / 2];
    }

    ~Symmetric()
    {
        delete[] Arr;
    }

    void Accept();
    void Display();
    int Access(int, int);
};

void Symmetric::Accept()
{
    cout << "Enter Values for Matrix:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> Arr[i * (i + 1) / 2 + j];
        }
    }
}

void Symmetric::Display()
{
    cout << "Matrix is:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i >= j)
            {
                cout << Arr[i * (i + 1) / 2 + j] << "\t";
            }
            else
            {
                cout << Arr[j * (j + 1) / 2 + i] << "\t";
            }
        }
        cout << endl;
    }
}

int Symmetric::Access(int i, int j)
{
    if (i >= j)
    {
        return Arr[i * (i + 1) / 2 + j];
    }
    else
    {
        return Arr[j * (j + 1) / 2 + i];
    }
}

int main()
{
    int no1 = 0, no2 = 0;
    int ret = 0;

    cout << "Enter Size of Matrix:" << endl;
    cin >> no1;

    Symmetric obj(no1);
    obj.Accept();
    obj.Display();

    cout << "Enter Indexes to access the element:" << endl;
    cin >> no1 >> no2;

    ret = obj.Access(no1, no2);
    cout << "Element at Indexes " << no1 << " " << no2 << " is " << ret << endl;

    return 0;
}