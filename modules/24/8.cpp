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

void skipMRemoveN(Node*& head, int m, int n) {
    // Skip 1 to m 
    //  then get m+1 Node
    // then traverse and delete m+1 nodes to m+n (EG 3+1 = 4 to m+n)
    // continue step until linked list didn't end
    cout << m << " " << n << endl;
    Node* temp = head;
    while (temp != NULL) {
        // Skip m
        for (int i = 1; i < m && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) return;
        // Delete N
        Node* temp2 = temp->next;
        for (int i = 1; i <= n && temp2 != NULL; i++) {
            Node* delNode = temp2;
            temp2 = temp2->next;
            delete delNode;
        }

        // Connect Remaining node
        temp->next = temp2;

        // start same process from the remaining node
        temp = temp2;
    }
}

int main() {
    Node* head = NULL;
    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (i == 0) {
            insertAtHead(head, val);
        }
        else {
            insertAtTail(head, val);
        }
    }
    skipMRemoveN(head, 3, 2);
    printList(head);
    return  0;
}