#include <bits/stdc++.h>

using namespace std;

class Student {
public:
  char name[50];
  int roll;
  int class_no;

private:
  int marks;

public:
  void setMarks(int x) { marks = x; }
  int getMarks() { return marks; }
};

int main() {
  Student anik;
  strcpy(anik.name, "Anik");
  anik.setMarks(500);
  cout << "Name: " << anik.name << endl << "Marks: " << anik.getMarks();

  return 0;
}

/**
 * Basic Class
 * Access  Specifier
 * Method / Function definations out of the class
 *  
 */


