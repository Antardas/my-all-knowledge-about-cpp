#include <bits/stdc++.h>
#include "STACK.H"
using namespace std;

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
   string check;
   cin >> check;
   cout << prefixEvaluation(check) << endl;
   return 0;
}