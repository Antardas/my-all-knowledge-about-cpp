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

public:
    void getEnglishMarks() {
        cout << english_marks << endl;
    }
};
int main() {
    Student abir;
    abir.getEnglishMarks();
    return 0;
}