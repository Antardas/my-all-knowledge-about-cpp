#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    int foundZ;
    int foundA = 0;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'Z') {
            foundZ = i + 1;
        }
        if (str[i] == 'A' && foundA == 0) {
            foundA = i + 1;
        }
    }
    cout << (foundZ - foundA) + 1 << endl;
    return 0;
}