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
/**
 * @brief Add node to head
 *
 * @param node
 * @param value
 */

void insertNodeAtHead(Node*& head, int value) {
    Node* newNode = new  Node(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}


void insertNodeAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
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

void printLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

void printReverseLinkedList(Node* head) {
    if (head == NULL) {
        return;
    }

    printReverseLinkedList(head->next);

    cout << head->value << "->";
}

void printr(Node* Head) {
    int Sum = 0;

    Node* Temp = Head;

    while (Temp->value != 14) {

        Sum += Temp->value;

        Temp = Temp->next;

    }

    Sum -= Temp->value;
    cout <<endl<< Sum << "end" << endl;

}

int main() {
    Node* head = NULL;
    int data;
    // cin >> data;
    // insertNodeAtHead(head, data);
    cin >> data;
    insertNodeAtTail(head, data);
    cin >> data;
    insertNodeAtTail(head, data);
    cin >> data;
    insertNodeAtTail(head, data);
    cin >> data;
    insertNodeAtTail(head, data);
    cin >> data;
    insertNodeAtTail(head, data);
    cin >> data;
    insertNodeAtTail(head, data);
    // printReverseLinkedList(head);
    printLinkedList(head);
    printr(head);
    return 0;
}