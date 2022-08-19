#include <bits/stdc++.h>

using namespace std;

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // move the previous element to the right
            j--;
        }
        arr[j + 1] = key; 
    }
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        int arr[size];
        for (int j = 0; j < size; j++) {
            cin >> arr[j];
        }
        /*         int avg = sum / size;
                int count = 0;
                for (int j = 0; j < size; j++) {
                    if (arr[j] > avg) {
                        count++;
                    }
                }
                cout << count << endl; */
        insertionSort(arr, size);
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }


    }
    return 0;
}










/*


 */