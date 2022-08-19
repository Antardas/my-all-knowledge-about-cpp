#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i]; // current
        int j = i - 1; // previous
        while (i >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}


int main() {
    int size, k;
    cin >> size;
    cin >> k;
    int arr[size];
    cout << "Enter your array list -> ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    insertionSort(arr, size);
    printArray(arr, size);
    if (size >= k) {
        cout << "Minimum : " << arr[k - 1] << endl << "Maximum : " << arr[size - k];
    }
    return 0;
}

/*
10 2
10 9 8 7 6 5 4 3 2 1

 */