#include <bits/stdc++.h>

using namespace std;


void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int current) {
    int largest = current;
    int leftChild = 2 * current + 1;
    int rightChild = 2 * current + 2;

    if (leftChild<n && arr[leftChild] > arr[largest]) {
        largest = leftChild;

    }
    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != current) {
        swap(arr[current], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n;i++) {
        cin >> arr[i];
    }

    int nonLeafStart = (n / 2) - 1;

    cout << "Before Heapify : ";
    printArray(arr, n);

    for (int i = nonLeafStart; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "After Heapify : ";
    printArray(arr, n);

    heapSort(arr, n);
    cout << "After Heap Sort : ";
    printArray(arr, n);


    return 0;
}

/*
9
2 10 1 5 4 8 3 8 7

 */