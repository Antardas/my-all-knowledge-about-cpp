/**
 * @file 1290_Convert_Binary_Number_in_a_Linked_List_to_Integer.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-06
 * @see https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;


/* Solution area start */

class Solution {
public:

    int list_size(ListNode* head) {
        int count = 0;
        while (head != NULL) {
            head = head->next;
            count++;
        }
        return count;
    }

    int getDecimalValue(ListNode* head) {
        int size = list_size(head);
        int power = pow(2, size - 1);
        int ans = 0;
        while (head != NULL) {
            if (head->val == 1) {
                ans += power;
            }

            head = head->next;
            power /= 2;
        }

        return ans;

    }
};
/* Solution area End */


int main() {

    return 0;
}