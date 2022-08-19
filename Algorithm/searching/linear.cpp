#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size;i++) {
        cin >> arr[i];
    }
    cout << "Array values : ";
    for (int i = 0; i < size;i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Please Enter the value you want to search : ";
    int searchValue;
    cin >> searchValue;
    for (int i = 0; i < size;i++) {
        if (arr[i] == searchValue) {
            cout << i << "th index";
        }
    }
    return 0;
}