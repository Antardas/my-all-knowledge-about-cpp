// #include <bits/stdc++.h>

// using namespace std;

// void insertionSort(int arr[], int size) {
//     for (int i = 1; i < size; i++) {
//         int key = arr[i]; // current item
//         int j = i - 1; // j for get previous item

//         while (j >= 0 && key < arr[j]) {
//             //if sorted | left side value is grater then key than swap right side
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//     }
// }

// int removeDuplicateItemsSortedList(int arr[], int size) {
//     int count = 0; // if find unique element then count++
//     int i = 0;
//     while (i < size) {
//         if (arr[i] != arr[i + 1]) {
//             arr[count] = arr[i];
//             count++;
//         }
//         i++;
//     }
//     return count;
// }


// int main() {
//     int n, m;
//     cin >> n;
//     int arr1[n], copyOfArray1[n];
//     int difference[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr1[i];
//         copyOfArray1[i] = arr1[i];
//     }

//     insertionSort(arr1, n);
//     int length1 = removeDuplicateItemsSortedList(arr1, n);
//     cin >> m;
//     int arr2[m];
//     for (int i = 0; i < m; i++) {
//         cin >> arr2[i];
//     }
//     insertionSort(arr2, m);
//     int length2 = removeDuplicateItemsSortedList(arr2, m);
//     int count = 0;
//     for (int i = 0; i < length1; i++) {
//         bool notFound = true;
//         for (int j = 0; j < length2; j++) {
//             if (arr1[i] == arr2[j]) {
//                 notFound = false;
//                 break;
//             }
//         }
//         if (notFound == true) {
//             difference[count] = arr1[i];
//             count++;
//         }
//     }
//     for (int i = 0; i < count; i++) {
//         cout << difference[i] << " ";
//     }
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

bool isExist(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }



    cin >> m;
    int arrB[m];
    int count = 0;
    for (int i = 0; i < m; i++) {
        cin >> arrB[i];
    }
    int difference[n];
    for (int i = 0; i < n; i++) {
        bool notFound = true;
        for (int j = 0; j < m; j++) {
            if (arr[i] == arrB[j]) {
                notFound = false;
                break;
            }
        }

        if (notFound == true && isExist(difference, n, arr[i]) == false) {
            difference[count] = arr[i];
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        cout << difference[i] << " ";
    }

    return 0;
}