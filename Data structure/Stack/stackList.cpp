#include <bits/stdc++.h>
#include "STACKLIST.H"

int globalId = 100;
using namespace std;
class Person {
    string name;
    int id;
    float salary;
public:
    Person() {
        name = "";
        id = -1;
        salary = -1.0;
    }
    void setName(string name) {
        this->name = name;
    }
    void setSalary(float salary) {
        this->salary = salary;
    }
    Person(string name, float salary) {
        setName(name);
        setSalary(salary);
        this->id = globalId++;
    }
    int getId() {
        return this->id;
    }
    string getName() {
        return this->name;
    }
    float getSalary() {
        return this->salary;
    }
    void print() {
        cout << "Name : " << this->name << endl;
        cout << "Id : " << this->id << endl;
        cout << "Salary : " << this->salary << endl;
    }
};

int main() {
    Stack <int> st;
    st.push(5);
    st.push(3);
    st.push(2);
    // Stack <pair<int, char>> st;
    // st.push(make_pair(1, 'a'));
    // st.push(make_pair(2, 'b'));
    // st.push(make_pair(3, 'c'));
    cout << "Empty : " << st.empty() << endl;
    cout << "Mid :  " << st.Mid() << endl;
    while (st.empty() == false) {
        cout << "Pop : " << st.pop() << endl;
    }


    // Stack <Person> person;
    return 0;
}