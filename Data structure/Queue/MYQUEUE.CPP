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
        if (rear == NULL) {
            cout << "Queue Underflow | There is no element in the list!!!" << endl;
        }
        Node* delNode = front;
        front = front->next;
        int check = delNode->value;
        delete delNode;
        return check;
    }
    // peek
    int peek() {

    }
    // empty
};

int main() {

    return 0;
}