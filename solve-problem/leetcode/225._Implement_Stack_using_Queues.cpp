/**
 *@file 225._Implement_Stack_using_Queues.cpp
 * @author Antar Das (antardas2334@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <bits/stdc++.h>

using namespace std;



class MyStack {
    int value;
public:
    queue<int>q1;
    MyStack() {
        int value;

    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        queue<int>q2;
        int ans;
        while (!q1.empty()) {
            int val = q1.front();
            q1.pop();
            if (q1.empty()) {
                ans = val;
                break;
            }
            q2.push(val);
        }
        q1 = q2;
        return ans;
    }

    int top() {
        queue<int>q2;
        int ans;
        while (!q1.empty()) {
            int val = q1.front();
            q1.pop();
            if (q1.empty()) {
                ans = val;
            }
            q2.push(val);
        }
        q1 = q2;
        return ans;
    }

    bool empty() {
        return q1.empty();
    }
};



int main() {

    return 0;
}