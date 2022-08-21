#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    if (value % 2 == 0) {
      cout << 2;
    }
  }
  return 0;
}