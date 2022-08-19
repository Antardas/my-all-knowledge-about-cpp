#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int checkValue, int lb, int ub) {
    int mid = (lb + ub) / 2;
    cout << mid << " " << lb << " " << ub;
    if (lb > ub) {
        return -1;
    }
    if (arr[mid] == checkValue) {
        return mid;
    }
    else if (arr[mid] < checkValue) {
        binarySearch(arr, checkValue, mid + 1, ub);
    }
    else if (arr[mid] > checkValue) {
        binarySearch(arr, checkValue, lb, mid - 1);
    }


}


int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Enter a number which number your want to search in your array : ";
    int check;
    cin >> check;
    int index = binarySearch(arr, check, 0, size - 1);
    cout << endl << "Your index is : " << index;
    return 0;
}

/*
10
1 6 9 41 52 65 77 80 82 89
6


 */