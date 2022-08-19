// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int row, col;
//     cout << "Enter the number of rows: ";
//     cin >> row;
//     cout << "Enter the number of columns: ";
//     cin >> col;
//     int matrix[row][col];
//     cout << "Enter the elements of matrix: " << endl;
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             cin >> matrix[i][j];
//         }
//     }
//     cout << "The matrix is: " << endl;
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get specific row
    int numbers[5][5];
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            cin >> numbers[r][c];
        }
    }

    // get 3 Number row
    cout << "Your third row numbers" << endl;
    for (int c = 0; c < 5; c++)
    {
        cout << numbers[2][c] << " ";
    }

    // get 2 Number col
    cout << endl << "Your second col numbers" << endl;
    for (int r = 0; r < 5; r++)
    {
        cout << numbers[r][1] << " ";
    }

    return 0;
}