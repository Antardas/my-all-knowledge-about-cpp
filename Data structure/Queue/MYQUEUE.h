#include <bits/stdc++.h>

using namespace std;


template <typename N> class Node {
public:
    N value;
    Node* next;
    Node(N val) {
        value = val;
        next = NULL;
    }
};

template <typename Q>class Queue {
    Node <Q>* front;
    Node <Q>* rear;
public:
    Queue() {
        cout << "call Queue" << endl;
        front = NULL;
        rear = NULL;
    }

    // Enqueue
    void push(Q val) {
        Node<Q>* newNode = new Node<Q>(val);
        if (front == NULL) {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
    }
    // Dequeue
    Q pop() {
        Q check;
        if (rear == NULL) {
            cout << "Queue Underflow | There is no element in the list!!!" << endl;
        }
        Node <Q>* delNode = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        check = delNode->value;
        delete delNode;
        return check;
    }
    // peek
    Q Front() {
        return front->value;
    }
    Q Back() {
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