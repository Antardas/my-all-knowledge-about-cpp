#include <bits/stdc++.h>

using namespace std;
class Student {
public:
  string name = "Antar Das";
  char section = 'A';
  int roll = 125;

protected:
  int english_marks = 56;

private:
  string password = "HFHFHFHFHFHHFHF";
};
int main() {
  int n;
  cout << "Enter your total number of students";
  cin >> n;
  Student students[n];
  for (int i = 0; i < n; i++) {
    students[i].name += char(i);
  }
  for (int i = 0; i < n; i++) {
    cout << students[i].name << endl;
  }

  return 0;
}