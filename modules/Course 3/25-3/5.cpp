#include <bits/stdc++.h>
#include "STACK.H"
using namespace std;


int precessionCalc(char c) {
    if (c == '^') {
        return 3;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

string infixToPrefix(string check) {
    reverse(check.begin(), check.end());
    Stack <char> st;
    string result;
    for (int i = 0; i < check.length(); i++) {
        if (check[i] >= '0' && check[i] <= '9') {
            result += check[i];
        }
        else if (check[i] == ')') { // after reverse its a opening bracket
            st.push(check[i]);
        }
        else if (check[i] == '(') { // after reverse its a closing bracket
            while (st.Top() != ')' && !st.empty()) { // It will continue to pop until it finds the opening bracket
                result += st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && precessionCalc(st.Top()) >= precessionCalc(check[i]))
            {
                result += st.pop();
            }
            st.push(check[i]);
        }
    }


    while (!st.empty()) {
        result += st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int prefixEvaluation(string check) {
    Stack <int> st;
    for (int i = check.length() - 1;i >= 0; i--) {
        if (check[i] >= '0' && check[i] <= '9') {
            st.push(check[i] - '0');
        }
        else {
            int a = st.pop();
            int b = st.pop();
            switch (check[i]) {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
                break;
            case '*':
                st.push(a * b);
                break;
                break;
            case '/':
                st.push(a / b);
                break;
                break;
            case '^':
                st.push(pow(a, b));
                break;
            default:
                break;
            }
        }
    }
    return st.pop();
}

int main() {
    // string check;
    // cin >> check;
    string infix = "(7+(4*5))-(2+0)";
    string prefix = infixToPrefix(infix);
    cout << prefix << endl;
    cout << prefixEvaluation(prefix) << endl;
    return 0;
}