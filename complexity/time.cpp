#include <bits/stdc++.h>

using namespace std;

int main() {

    int a = 0;
    int N = 5;
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = N; j > i; j--) {
            a = a + i + j;
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}