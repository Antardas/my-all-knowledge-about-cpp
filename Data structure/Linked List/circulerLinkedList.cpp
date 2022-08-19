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

void printList(Node* head) {
    Node* temp = head;
    if (head == NULL) {
        cout << "The Linked list is Empty" << endl;
    }
    cout << "This List value is : ";
    do {
        cout << temp->value;
        temp = temp->next;
        if (temp != head) {
            cout << "-> ";
        }
    } while (temp != head);
    cout << endl;
    return;
}

int countListLength(Node* head) {
    Node* temp = head;
    if (head == NULL) return 0;
    int count = 0;
    do {
        temp = temp->next;
        count++;
    } while (temp != head);
    return count;
}

void insertAtHead(Node*& head, int value) {
    Node* temp = head;
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    head = newNode;

    return;
}

void insertionAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;// newNode || last node = head
    temp->next = newNode; // 2nd last node next = newNode
}

void deleteHead(Node*& head) {
    if (head == NULL) {
        cout << "This list doesn't contain any value.";
        return;
    }

    Node* temp = head;
    Node* delNode = temp; // set Head node as a delete node 
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = delNode->next; // set last node 2nd head node
    head = delNode->next; // head = 2nd head node
    delete delNode; // delete main head
}

void deleteAtTail(Node*& head) {
    Node* temp = head;
    if (temp == NULL) {
        cout << "There is not linked list in the list" << endl;
        return;
    }
    while (temp->next->next != head) {
        temp = temp->next;
    }
    Node* headNode = temp->next->next;
    delete temp->next;
    temp->next = headNode;
}
int main() {
    int value, postion, option;
    cout << "Option 0: Terminate Program" << endl
        << "Option 1: Insertion At Head" << endl
        << "Option 2: Insertion At Tail" << endl
        << "Option 3: Deletion At Head" << endl
        << "Option 4: Deletion At Tail" << endl
        << "Option 5: Print Linked list" << endl
        << "-------------------------------------" << endl;

    Node* head = NULL;
    cout << "Next Option : ";
    cin >> option;
    while (option != 0) {
        switch (option)
        {
        case 1:
            cout << "Enter value you want add in head : ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter value you want add in Tail : ";
            cin >> value;
            insertionAtTail(head, value);
            break;
        case 3:
            deleteHead(head);
            break;
        case 4:
            deleteAtTail(head);
            break;
        case 5:
            printList(head);
            break;
        case 6:
            countListLength(head);
            break;
        default:
            break;
        }
        cout << "Next Option : ";
        cin >> option;
    }

    printList(head);
    cout << "The List Length list : " << countListLength(head) << endl;

    return 0;
}

// 1 1 2 2 2 3 2 4