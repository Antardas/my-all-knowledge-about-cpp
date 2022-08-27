

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

Node* reverseNodeByK(Node*& head, int k) {
    cout << "Run" << endl;
    if (head == NULL) return NULL;
    Node* prev = NULL;
    Node* cur = head;
    Node* next = NULL;
    int count = 0;
    while (count < k && cur != NULL) {
        next = cur->next;
        cur->next = prev; // change link
        prev = cur;
        cur = next;
        count++;
    }
    if (next != NULL) {
        head->next = reverseNodeByK(next, k); // after k time reverse its return group of reverse node than its save in head->next
    }
    return prev;

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
    int k;
    cin >> k;
    head = reverseNodeByK(head, k);
    printList(head);
    return  0;
}