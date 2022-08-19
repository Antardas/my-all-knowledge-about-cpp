#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(int number) {
    int reversed_number = 0, original_number = number;
    while (number > 0) {

        int reminder = number % 10;
        reversed_number = (reversed_number * 10) + reminder;
        number = number / 10;
    }
    if (reversed_number == original_number) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    int number;
    cin >> number;
    if (checkPalindrome(number)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}