#include <bits/stdc++.h>

using namespace std;
template<typename N>  class Node {
public:
    N value;
    Node* prev;
    Node* next;

    Node(N val) {
        this->value = val;
        Node* prev = NULL;
        Node* next = NULL;
    }
};

template <typename S> class Stack {
    Node <S>* head;
    Node <S>* top;
    int count = 0;
public:
    Stack() {
        head = NULL;
        top = NULL;
    }

    // Push

    void push(S val) {
        Node <S>* newNode = new Node<S>(val);
        if (head == NULL) {
            head = top = newNode;
            count++;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;

    }
    // POP
    S pop() {

        Node <S>* delNode;
        delNode = top;
        S check;
        if (head == NULL) {
            cout << "Stack UnderFlow" << endl;

            return check;
        };
        if (top == head) {
            head = top = NULL;
        }
        else { // there is more than element
            top = delNode->prev;
            top->next = NULL;
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


    // Size
    int size() {
        return count;
    }

};