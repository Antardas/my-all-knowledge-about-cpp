#include <bits/stdc++.h>
#include "MYQUEUE.h"
using namespace std;

int main() {

    Queue qu;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        qu.push(val);
    }

    while (!qu.empty()) {
        cout << qu.pop() << endl;
    }
    return 0;
}

