#include <bits/stdc++.h>

using namespace std;
/**
 * @brief bubble sort
 *
 * @param arr
 * @param size
 */
void bubbleSort(int arr[], int size) {
   // pseudo code
   // for i = 0 to size - 1
   //   for j = 0 to size - i - 1
   //     if arr[j] > arr[j + 1]
   //       swap(arr[j], arr[j + 1])
   // end for

   for (int i = 0; i < size - 1; i++) {
      bool sorted = true;
      for (int j = 0; j < size - i - 1; j++) {

         if (arr[j] > arr[j + 1]) {
            // cout << "Swap " << arr[j] << " and " << arr[j + 1] << endl;
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            sorted = false;
         }
      }
      if (sorted) {
         break;
      }
   }

   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }


}

int main() {
   int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
   int size = sizeof(arr) / sizeof(arr[0]);
   bubbleSort(arr, size);
   return 0;
}