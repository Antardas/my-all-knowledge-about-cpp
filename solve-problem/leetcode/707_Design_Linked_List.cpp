#include <bits/stdc++.h>

using namespace std;
class MyLinkedList {
public:
    int val;
    MyLinkedList* head;
    MyLinkedList* next;
    MyLinkedList() {
        this->head = NULL;

    }
    MyLinkedList(int value) {
        val = value;
        this->next = NULL;
    }

    int get(int index) {
        MyLinkedList* temp = head;
        for (int i = 1; i <= index; i++) {
            temp = temp->next;
            if (temp == NULL) break;
        }
        if (temp == NULL) {
            return -1;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        if (head == NULL) {
            head = new MyLinkedList(val);
            return;
        }

        MyLinkedList* newHead = new MyLinkedList(val);

        newHead->next = head;
        head = newHead;
    }

    void addAtTail(int val) {
        MyLinkedList* newNode = new MyLinkedList(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        MyLinkedList* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {
        MyLinkedList* newNode = new MyLinkedList(val);
        
        if (index == 0) {
            addAtHead(val);
            return;
        }
        MyLinkedList* temp = head;
        for (int i = 1; i <= index - 1;i++) {
            temp = temp->next;
            if (temp == NULL) break;
        }
        if (temp == NULL) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (head == NULL) {
            return;
        }
        if (index == 0) {
            MyLinkedList* del = head;
            head = head->next;
            delete del;
            return;

        }
        MyLinkedList* temp = head;
        for (int i = 1; i <= index-1;i++) {
            temp = temp->next;
            if (temp == NULL) {
                break;
            }
        }
        if (temp == NULL) {
            return;
        }
        MyLinkedList* del = temp->next;
        if (del == NULL) return;
        temp->next = temp->next->next;
        delete del;

    }
};
int main() {

    return 0;
}

