/**
 *@file 876_Middle_of_the_Linked_List.cpp
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
    ListNode* middleNode(ListNode* head) {
        int size = list_size(head);
        int mid = size / 2;
        for (int i = 1; i <= mid; i++) {
            head = head->next;
        }
        return head;
    }
};


int main() {

   return 0;
}