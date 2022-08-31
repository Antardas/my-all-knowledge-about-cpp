#include <bits/stdc++.h>
#include "QUEUE.h"
#include "STACK.h"

using namespace std;
/*
11 3
1 2 3 4 5 6 7 8 9 10 11
-> 3 2 1 6 5 4 9 8 7 11 10
 */

void reverseKElements(int n, int k, Queue<int>& qu) {
   int x = n / k;
   int y = n % 5;

   Stack <int> st;
   while (x > 0) {
      int check = k;
      while (check > 0) {
         st.push(qu.pop());
         check--;
      }
      while (!st.empty()) {
         qu.push(st.pop());
      }
      x--;
   }

   while (y > 0) {
      st.push(qu.pop());
      y--;
   }
   while (!st.empty()) {
      qu.push(st.pop());
   }

}
int main() {
   Queue <int> qu;
   int n, k;
   cin >> n;
   cin >> k;
   for (int i = 1; i <= n; i++) {
      int val;
      cin >> val;
      qu.push(val);
   }

   reverseKElements(n, k, qu);
   while (!qu.empty())
   {
      cout << qu.pop() << " ";
   }

   cout << endl;
   


   return 0;
}