/* #include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    /* for (int k = 0; k < n; k++) {
        for (int i = k; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[k][i] == arr[i][j + 1]) {
                    arr[i][j + 1] = -1;
                }
            }
        }
    } */
// for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//         if (arr[i][0] == arr[i][j + 1] &&) {
//             arr[i][j + 1] = -1;
//         }
//     }
// }

/*

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cout << arr[i][j] << " ";
    }
    cout << endl;
}
return 0;
}




*/




#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    int array[r][c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> array[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int val = array[i][j];
            int count = 0;
            for (int x = 0; x < r; x++)
            {
                for (int y = 0; y < c; y++)
                {
                    if (val == array[x][y])
                    {
                        if (count > 0)
                        {
                            array[x][y] = -1;
                        }
                        count++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
2 6
2 2 2 2 2 2
6 5 4 3 2 1


 */
