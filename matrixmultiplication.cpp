#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <omp.h>

#define MAX 100

using namespace std;

int main()
{
    int r = 3, c = 2;
    int matrix[r][c], vector[c], out[r];
    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            matrix[row][col] = 1;
        }
    }

    cout << "Input Matrix" << endl;

    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            cout << "\t" << matrix[row][col];
        }
        cout << "" << endl;
    }
    for (int col = 0; col < c; col++)
    {
        vector[col] = 2;
    }
    cout << "Input Col-Vector" << endl;

    for (int col = 0; col < c; col++)
    {
        cout << vector[col] << endl;
    }

#pragma omp parallel
    {
#pragma omp for
        for (int row = 0; row < r; row++)
        {
            out[row] = 0;
            for (int col = 0; col < c; col++)
            {
                out[row] += matrix[row][col] * vector[col];
            }
        }
    }
    cout << "Resultant Col-Vector" << endl;
    for (int row = 0; row < r; row++)
    {
        cout << "\nvector[" << row << "]:" << out[row] << endl;
    }
    return 0;
}