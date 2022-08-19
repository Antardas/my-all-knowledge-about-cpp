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
  Student abir;
  cout << abir.name << abir.roll << abir.section << endl;

  return 0;
}