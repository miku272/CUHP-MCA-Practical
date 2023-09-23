/*
Write a program to multiply two matrices
*/

#include <iostream>

#define R1 3
#define R2 3
#define C1 3
#define C2 3

void matrix_multiply(int arr1[][C1], int arr2[][C2])
{
    int res[R1][C2];

    // Multiplying
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            for (int k = 0; k < R2; k++)
            {
                res[i][j] = arr1[i][k] * arr2[k][j];
            }
        }
    }

    // Print result
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    int arr1[R1][C1] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int arr2[R2][C2] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    matrix_multiply(arr1, arr2);

    return 0;
}
