#include <bits/stdc++.h>

using namespace std;

void sortString(string& s) {
    int size = s.size();
    for (int i = 1; i < size; i++) {
        int key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j] > key) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        sortString(str);
        cout << str << endl;
    }
    return 0;
}