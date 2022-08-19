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
    void getPassword() {
        cout << password << endl;
    }
    void setMarks(int newMarks) {
        english_marks = newMarks;
    }
};
int main() {
    Student abir;
    abir.setMarks(50);
    abir.getEnglishMarks();

    return 0;
}