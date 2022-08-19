#include <bits/stdc++.h>

using namespace std;

int main() {
    int solved;
    int total = 0;
    for (int i = 0; i < 4; i++) {
        cin >> solved;
        if (solved >= 10) {
            total++;
        }
    }
    cout << total << endl;


    return 0;
}