
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n;j++) {
            cin >> arr[i][j];
        }
    }


    int mid = (n / 2);
    int sum = 0;
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n;j++) {
            if (i == 0 && j <= mid) { // first line
                sum += arr[i][j];
            }
            else if (i == 0 && j == n - 1) { // first line
                sum += arr[i][j];
            }
            else if (i > 0 && i < mid && j == mid) { // 2nd to mid--1
                sum += arr[i][mid];
                sum += arr[i][n - 1];
            }
            else if (i == mid) { // mid line
                sum += arr[i][j];
            }
            else if (i > mid && i < n - 1 && j == mid) { // mid+1 to n-1 line
                sum += arr[i][0];
                sum += arr[i][mid];

            }
            else if (i == n - 1 && j == 0) { // last line
                sum += arr[i][0];
            }
            else if (i == n - 1 && j >= mid) { // last line
                sum += arr[i][j];
            }

        }

    }


    cout << sum;

    return 0;
}

/*
5
1 2 3 4 5
2 3 4 1 6
3 4 9 6 7
4 2 6 7 8
5 4 3 2 1


 */