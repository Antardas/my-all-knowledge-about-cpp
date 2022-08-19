// antar100

#include <bits/stdc++.h>

using namespace std;

int main() {
    int numbers[3];
    for (int i = 0; i < 3; i++) {
        cin >> numbers[i];
    }
    int different = 0;
    if (numbers[0] != numbers[1]) {
        different++;
    }
    if (numbers[1] != numbers[2]) {
        different++;
    }
    if (numbers[0] != numbers[2]) {
        different++;
    }
    if(numbers[0]==numbers[1] && numbers[1]==numbers[2]){
       different++;
     }
    cout << different << endl;
    return 0;
}