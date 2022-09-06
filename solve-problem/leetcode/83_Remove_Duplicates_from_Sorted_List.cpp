/**
 * @file 83_Remove_Duplicates_from_Sorted_List.cpp
 * @author Antar Das (antardas2334@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

/* Solution Area Start */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* mainHead = head;
        while (head != NULL) {
            ListNode* current = head;
            ListNode* next = head->next;
            if (next == NULL) {
                break;
            }

            if (current->val == next->val) {
                head->next = next->next;
                delete next;

            }
            else {
                head = next;
            }
        }
        return mainHead;
    }
};

/* Solution Area End */

int main() {

    return 0;
}