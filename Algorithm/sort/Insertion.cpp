#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int size) {
    // Print array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}



int main() {
    // input array with size
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < size; i++) {
        int key = arr[i]; // key is the current element
        int j = i - 1; // j is the previous element
        while (j >= 0 && arr[j] > key) { // while the previous element is greater than the current element
            arr[j + 1] = arr[j]; // move the previous element to the right
            j--;
        }
        arr[j + 1] = key; // insert the current element at the correct position
    }
    printArray(arr, size);
    return 0;
}