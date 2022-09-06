/**
 * @file 237_Delete_Node_in_a_Linked_List.cpp
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

/* Solution area start */


class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete temp;

    }
};
/* Solution area End */
int main() {

    return 0;
}