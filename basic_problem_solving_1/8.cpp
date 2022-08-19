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

    void setPassword(string newPassword) {
        password = newPassword;
    }
};
int main() {
    int n;
    cout << "Enter your total number of students => " << endl;
    cin >> n;
    Student students[n];

    for (int i = 0; i < n; i++) {
        string pass;
        int mark;
        cin >> students[i].name >> students[i].roll >> students[i].section >> pass >> mark;
        students[i].setPassword(pass);
        students[i].setMarks(mark);
    }

    for (int i = 0; i < n; i++) {

        cout << students[i].name << " " << students[i].roll << " " << students[i].section;
        students[i].getPassword();
        students[i].getEnglishMarks();
        cout << endl;
    }


    return 0;
}