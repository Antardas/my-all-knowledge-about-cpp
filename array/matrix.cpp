// Diagonal matrix sum

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int row, col;
    cout << "Enter your row number: ";
    cin >> row;
    cout << "Enter your col number: ";
    cin >> col;
    int numbers[row][col];

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cin >> numbers[r][c];
        }
    }

    int sum = 0;

    for (int r = 0; r < row; r++)
    {
        sum += numbers[r][r];
    }
    cout << sum << endl;
}

/* 

1 2 3 4 5
4 5 6 9 8
4 5 6 2 3
4 6 3 2 1
7 5 6 3 2

 */