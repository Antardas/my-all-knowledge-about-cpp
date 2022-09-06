#include <bits/stdc++.h>

using namespace std;
template<typename N>  class NodeQueue {
public:
    N value;
    NodeQueue* prev;
    NodeQueue* next;

    NodeQueue(N val) {
        this->value = val;
        NodeQueue* prev = NULL;
        NodeQueue* next = NULL;
    }
};

template <typename S> class Stack {
    NodeQueue <S>* head;
    NodeQueue <S>* top;
    NodeQueue <S>* mid;
    int count = 0;
public:
    Stack() {
        head = NULL;
        top = NULL;
        mid = NULL;
    }

    // Push

    void push(S val) {
        NodeQueue <S>* newNode = new NodeQueue<S>(val);
        if (head == NULL) {
            head = top = newNode;
            mid = top;
            count++;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        if (count % 2 == 0) {
            mid = mid->next;
        }
        count++;

    }
    // POP
    S pop() {

        NodeQueue <S>* delNode;
        delNode = top;
        S check;
        if (head == NULL) {
            cout << "Stack UnderFlow" << endl;

            return check;
        };
        if (top == head) {
            head = top = NULL;
            mid = NULL;
        }
        else { // there is more than element
            top = delNode->prev;
            top->next = NULL;
            if (count % 2 == 0) {
                mid = mid->prev;
            }
        }
        check = delNode->value;
        delete delNode;
        count--;
        return check;

    }
    // Empty
    bool empty() {
        if (head == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    // Top
    S Top() {
        if (top == NULL) {
            cout << "Stack Underflow: There is not element in the top";
        }
        else {
            return top->value;
        }
    }

    S Mid() {
        return mid->value;
    }


    // Size
    int size() {
        return count;
    }

};