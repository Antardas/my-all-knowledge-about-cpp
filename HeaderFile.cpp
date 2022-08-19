#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void testFunc(int* num) {
  *num = 100;
  cout << "First : " << *num << endl;
}
int main() {

  // string s1 = "HelloWorld";
  // string s2 = s1.substr(5, 5);
  // cout << s2.substr(3, 2);
  int num2 = 10;
  int* num = num;
  testFunc(num);
  cout << "Second: " << num2 << endl;
}