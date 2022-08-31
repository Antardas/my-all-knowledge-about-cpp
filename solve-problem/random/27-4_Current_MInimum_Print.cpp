#include <bits/stdc++.h>
#include "STACK.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    int min = INT_MAX;
    Stack <int>st;
    Stack <int>stMin;


    for (int i = 0; i < n; i++) {
        if (array[i] <= min) {
            stMin.push(array[i]);
            min = array[i];
        }
        st.push(array[i]);
    }


    while (!st.empty()) {
        if (st.Top() != stMin.Top()) {
            cout << stMin.Top() << " ";
            st.pop();
        }
        else {
            cout << stMin.Top() << " ";
            stMin.pop();
            st.pop();
        }
    }
    return 0;
}