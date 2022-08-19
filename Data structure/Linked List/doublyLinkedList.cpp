#include <bits/stdc++.h>

using namespace std;

class DoublyNode {
public:
    int value;
    DoublyNode* prev;
    DoublyNode* next;
    DoublyNode(int value) {
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printList(DoublyNode*& head) {
    cout << "run print list";
    DoublyNode* temp = head;
    while (temp != NULL) {
        cout << temp->value << "->\033[1;31m ";
        temp = temp->next;
    }
    cout << endl;
}

void printReverse(DoublyNode*& head) {
    DoublyNode* temp = head;
    // Get tail node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // reverse it
    while (temp != NULL) {
        cout << temp->value << " --> ";
        temp = temp->prev;
    }
}

int listLength(DoublyNode*& head) {
    int count = 0;
    DoublyNode* temp = head;
    while (temp->next != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}



void insertAtHead(DoublyNode*& head, int value) {
    DoublyNode* newDoublyNode = new DoublyNode(value);
    if (head == NULL) {
        head = newDoublyNode;
        return;
    }

    DoublyNode* temp = head;
    newDoublyNode->next = head;
    head->prev = newDoublyNode;


}

void insertAtTail(DoublyNode*& head, int value) {
    DoublyNode* newDoublyNode = new DoublyNode(value);
    if (head == NULL) {
        return;
    }

    DoublyNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newDoublyNode;
    newDoublyNode->prev = temp;
}
int main() {
    DoublyNode* head = NULL;


    cout << "Option 1: Insertion at Head" << endl
        << "Option 2: Insertion at Tail" << endl
        << "Option 0 : EXIT" << endl;
    int choice = 1;
    while (choice != 0) {
        int value;
        cout << "Your next choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the value : ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value : ";
            cin >> value;
            insertAtTail(head, value);
            break;
        default:
            cout << "Command Not found" << endl;
            break;
        }
        if (choice == 0) { break; }

    }


    printList(head);
    cout << "Reverse List" << endl;
    printReverse(head);
    cout << "Our list length is : " << listLength(head);
    return 0;
}