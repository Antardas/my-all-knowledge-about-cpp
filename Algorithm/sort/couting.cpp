#include <bits/stdc++.h>

using namespace std;
void printArray(int array[], int size) {
   for (int i = 0; i < size; i++)
   {
      cout << array[i] << " ";
   }
   cout << endl;

}
int main() {
   int size;
   cin >> size;
   int array[size];
   // Input value
   for (int i = 0; i < size; i++)
   {
      cin >> array[i];
   }

   // Step 1: Find max
   int max = INT_MIN;
   for (int i = 0; i < size; i++)
   {
      if (array[i] > max) {
         max = array[i];
      }
   }

   // Step 2: initialize count array this array size is MAX+1 after set all value is 0
   int count[max + 1];

   for (int i = 0; i < max + 1; i++)
   {
      count[i] = 0;
   }

   // step 3: Frequency calculation

   for (int i = 0; i < size; i++) {
      count[array[i]]++;
   }
   cout << "Frequency calculation" << endl;
   printArray(count, max+1);
   // step 4: Cumulative Sum



   for (int i = 1; i <= max; i++) {
      count[i] += count[i - 1];
   }
   cout << "Cumulative Sum" << endl;
   printArray(count, max+1);
   // Step 5 : Final Array Backward traversal of Basic Array
   int final[size];
   for (int i = size - 1; i >= 0; i--) {
      count[array[i]]--;
      int k = count[array[i]];
      final[k] = array[i];
   }
   printArray(final, size);
   return 0;
}

// counting sort step
// 1. Find max
// 2. Initialize count array this array size is MAX+1 after set all value is 0
// 3. Frequency calculation
// 4. Cumulative Sum
// 5. Final Array Backward traversal of Basic Array
// Time complexity: O(n)