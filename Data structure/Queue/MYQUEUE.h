#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;
public:
    Queue() {
        cout << "call Queue" << endl;
        front = NULL;
        rear = NULL;
    }

    // Enqueue
    void push(int val) {
        Node* newNode = new Node(val);
        if (front == NULL) {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
    }
    // Dequeue
    int pop() {
        int check = -1;
        if (rear == NULL) {
            cout << "Queue Underflow | There is no element in the list!!!" << endl;
        }
        Node* delNode = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        check = delNode->value;
        delete delNode;
        return check;
    }
    // peek
    int Front() {
        return front->value;
    }
    int Back() {
        return rear->value;
    }
    // empty
    bool empty() {
        if (front != NULL) {
            return false;
        }
        else {
            return true;
        }
    }
};