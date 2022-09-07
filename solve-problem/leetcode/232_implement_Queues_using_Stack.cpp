/**
 * @file 225_implement_Stack_using_Queues.cpp
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
class MyQueue {
public:
    stack<int>s1;

    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        stack<int> s2;
        int ans;
        while (!s1.empty()) {
            int val = s1.top();
            s1.pop();
            if (s1.empty()) {
                ans = val;
                break;
            }
            s2.push(val);
        }
        while (!s2.empty()) {
            int val = s2.top();
            s2.pop();
            s1.push(val);
        }
        return ans;
    }

    int peek() {
        stack<int> s2;
        int ans;
        while (!s1.empty()) {
            int val = s1.top();
            s1.pop();
            if (s1.empty()) {
                ans = val;
            }
            s2.push(val);
        }
        while (!s2.empty()) {
            int val = s2.top();
            s2.pop();
            s1.push(val);
        }
        return ans;
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {

    return 0;
}