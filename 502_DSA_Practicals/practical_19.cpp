#include <iostream>
using namespace std;

class LowerTriangularMatrix
{
private:
    int size;
    int *arr;

public:
    LowerTriangularMatrix(int n)
    {
        size = n;
        arr = new int[n * (n + 1) / 2];
    }

    void set(int i, int j, int value)
    {
        if (i >= j)
        {
            int index = i * (i + 1) / 2 + j;
            arr[index] = value;
        }
    }

    int get(int i, int j)
    {
        if (i >= j)
        {
            int index = i * (i + 1) / 2 + j;
            return arr[index];
        }
        return 0;
    }
};

int main()
{
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    LowerTriangularMatrix matrix(n);

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value;
            cin >> value;
            matrix.set(i, j, value);
        }
    }

    cout << "Lower Triangular Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix.get(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
