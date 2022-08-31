#include <bits/stdc++.h>
#include "STACK.h"

using namespace std;
bool balanceParenthesis(string check) {
    int n = check.size();
    if (n % 2 != 0) {
        return false;
    }
    Stack <char> st;
    bool isBalanced = true;
    for (int i = 0; i < n;i++) {
        if (check[i] == '[' || check[i] == '{' || check[i] == '(') {
            st.push(check[i]);
        }
        else if (check[i] == ')') {
            if (st.Top() == '(') {
                st.pop();
            }
            else {
                isBalanced = false;
                break;
            }
        }
        else if (check[i] == '}') {
            if (st.Top() == '{') {
                st.pop();
            }
            else {
                isBalanced = false;
                break;
            }
        }
        else if (check[i] == ']') {
            if (st.Top() == '[') {
                st.pop();
            }
            else {
                isBalanced = false;
                break;
            }
        }
    }
    if (!st.empty()) {
        return false;
    }
    return isBalanced;

}
int main() {
    string check;
    cin >> check;
    cout << balanceParenthesis(check) << endl;
    return 0;
}