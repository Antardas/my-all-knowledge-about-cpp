#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int value;
    Node* next;
    Node(int val) {
        this->value = val;
        this->next = NULL;
    }
};
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    cout << "Call Print Function" << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value;
        temp = temp->next;
        if (temp != NULL) {
            cout << "-> ";
        }
    }
}

int main() {
    Node* head = NULL;
    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (val % 2 == 0) {
            val = -1;
        }
        if (i == 0) {
            insertAtHead(head, val);
        }
        else {
            insertAtTail(head, val);
        }
    }
    printList(head);
    return  0;
}