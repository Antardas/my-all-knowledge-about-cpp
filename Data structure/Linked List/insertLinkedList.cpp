#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = NULL;
    }
};

struct Test {
    int positions[1000];
};

void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    // if head is NULL, then make newNode as head
    if (head == NULL) {
        head = newNode;
        return;
    }
    // if head is not NULL, then find the last node and insert newNode after it
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;

}


void insertAtHead(Node*& head, int value) {
    // create a new node with value
    Node* newNode = new Node(value);
    // if head is NULL, then make newNode as head

    if (head == NULL) {
        head = newNode;
        return;
    }
    // if head is not NULL, then make newNode as next of head and make head as newNode
    newNode->next = head;
    head = newNode;

}

void displayLinkedList(Node* head) {
    cout << "Linked List: ";
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

// Get length of the linked list

int getLength(Node*& head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    return length;
}

// Insertion add specific Position

/**
 * @brief Insert value specific position
 *
 * @param head
 * @param pos
 * @param val
 */
void insertionAtSpecificPosition(Node*& head, int pos, int val) {
    int i = 0;
    Node* temp = head; // 1

    while (i < pos - 2) { //3 < 5 - 2 = 3
        temp = temp->next; // 2 3 4
        i++; // 1 2 3
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next; // 4 -> 5
    temp->next = newNode; // 3 -> 4

}

int searchPositionByUniqueValue(Node*& head, int value) {
    Node* temp = head;
    int count = 1;
    while (temp->value != value) {
        if (temp == NULL) {
            return -1;
        }
        temp = temp->next;
        count++;
    }
    return count;
}

// Task: Insertion at specific position multiple times


void searchPositionByDuplicateValue(Node*& head, int value) {
    Node* temp = head;
    int size = getLength(head);
    int positions[size + 1], k = 1;
    int count = 1;
    int found = 0;
    while (temp != NULL) {
        if (temp->value == value) {
            found = 1;
            positions[k] = count;
            k++;
        }
        temp = temp->next;
        count++;
    }
    if (found == 0) { cout << endl << "Your searched value not yet in the list" << endl; }
    else {
        positions[0] = k;
        for (int i = 1; i < positions[0]; i++) {
            cout << positions[i];
            if (i + i != positions[0]) {
                cout << ", ";
            }
        }
    }

}


Test searchPositionByDuplicateValueReturn(Node*& head, int value) {
    Node* temp = head;
    int size = getLength(head);
    int k = 1;
    int count = 1;
    Test test;
    while (temp != NULL) {
        if (temp->value == value) {
            test.positions[k] = count;
            k++;
        }
        temp = temp->next;
        count++;
    }
    test.positions[0] = k;
    return test;
}

void searchByValueUnique(Node*& head, int searchValue, int newValue) {
    // get position of searchValue
    int postion = searchPositionByUniqueValue(head, searchValue);
    if (postion == -1) {
        cout << endl << "Your searched value not yet in the list" << endl;
    }
    else {
        // insert newValue at after the position
        insertionAtSpecificPosition(head, postion, newValue);
    }
}

// void insertionAfterAtSpecificUniqueValue(Node*& head, int value, int newValue) {

//     Node* temp = head;

//     while (temp->value != value) {
//         temp = temp->next;
//     }
//     Node* newNode = new Node(newValue);
//     newNode->next = temp->next;
//     temp->next = newNode;

// }

// Delete head node 
void deleteHead(Node*& head) {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete tail node
void deleteTail(Node*& head) {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    if (temp->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

// Delete specific node
void deleteSpecificNode(Node*& head, int postion) {
    if (head == NULL) {
        return;
    }
    if (postion == 1) {
        delete head;
        return;
    }
    int i = 1;
    Node* temp = head;
    while (i < postion - 1) {
        temp = temp->next;
        i++;
    }
    Node* temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
    return;
}

Node* reverseNonRecursive(Node*& head) {
    if (head == NULL) return head;
    Node* prev = NULL;
    Node* cur = head;
    Node* next = head->next;
    while (true) {
        cur->next = prev;
        prev = cur;
        cur = next;
        if (cur == NULL) break;
        next = next->next;
    }


    return prev;
}

int slowFast(Node*& head) {
    if (head == NULL) return -1;
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return slow->value;
}

void makeCycle(Node*& head, int pos) {
    int count = 1;
    cout << "pos " << pos << endl;
    Node* temp = head;
    Node* startCycle;
    while (temp->next != NULL) {
        if (count == pos) startCycle = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startCycle;

}

// detect cycle
bool detectCycle(Node*& head) {
    if (head == NULL) return false;
    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        // Cycle check
        if (slow->next == fast->next) {
            cout << "Cycle check" << endl;

            return true;
        }
    }
    return false;
}

// Remove cycle
void removeCycle(Node*& head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: fast = slow
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != slow);
    // Step 2: Re initialize fast
    fast = head;
    // step 3: fast->next = slow->next
    while (fast->next != slow->next) {
        slow = slow->next;
        fast = fast->next;
    }

    //  step 4 : slow->next = NULL
    slow->next = NULL;

}

int main() {

    Node* head = NULL;
    char choice = 'Y';

    cout
        << "Option 0: Break this process" << endl
        << "Option 1: Add value on head" << endl
        << "Option 2: add value on tail" << endl
        << "Option 3: add value in specific postion" << endl
        << "Option 4: Search Postion by unique value" << endl
        << "Option 5: Search all position by value" << endl
        << "Option 6: Insertion after a specific value" << endl
        << "Option 7: Delete head node" << endl
        << "Option 8: Delete tail node" << endl
        << "Option 9: Delete specific node" << endl
        << "Option 10: Reversal of a list (NoN Recursive)" << endl
        << "Option 11: Using slow fast method get mid" << endl
        << "Option 12: Make a cycle" << endl
        << "Option 13: Check a cycle" << endl
        << "Option 14: Delete a cycle" << endl


        << "--------------------------------------------------" << endl;
    while (choice == 'Y' || choice == 'y') {
        int value, position, option, newValue;


        cout << "Enter your Choice : ";


        cin >> option;
        switch (option)
        {
        case 0:
            choice = 'N';
            cout << "You have exited the program" << endl;
            break;
        case 1:
            cout << "Enter the value to insert at head: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value to insert at tail: ";

            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter postion you want to add" << endl;
            cin >> position;
            cout << "Enter value you want to add" << endl;
            cin >> value;
            insertionAtSpecificPosition(head, position, value);
            break;
        case 4:
            cout << "Enter the value you want to search";
            cin >> value;
            position = searchPositionByUniqueValue(head, value);
            if (position != -1) {
                cout << "The number of Position is : " << position << endl;
            }
            else {
                cout << "The number is not yet available in this list" << endl;
            }
            break;
        case 5:
            cout << "Enter the value you want to search : ";
            cin >> value;
            Test test;
            test = searchPositionByDuplicateValueReturn(head, value);
            if (test.positions[0] >= 2) {
                for (int i = 1; i < test.positions[0]; i++) {
                    cout << test.positions[i] << " ";
                }
            }
            else {
                cout << "The search value not yet in the list";
            }
            break;
        case 6:
            cout << "Enter the value you want to search : ";
            cin >> value;
            cout << "Enter the new value you want to insert : ";
            cin >> newValue;
            // insertionAfterAtSpecificUniqueValue(head, value, newValue);
            searchByValueUnique(head, value, newValue);
            break;
        case 7:
            deleteHead(head);
            break;
        case 8:
            deleteTail(head);
            break;
        case 9:
            cout << "Enter the postion you want to delete : ";
            cin >> position;
            deleteSpecificNode(head, position);
            break;
        case 10:
            head = reverseNonRecursive(head);
            break;
        case 11:
            cout << "The mid value is : " << slowFast(head) << endl;
            break;
        case 12:
            cout << "Enter the postion you want to make a cycle : ";
            cin >> position;
            makeCycle(head, position);
            break;
        case 13:
            bool found;
            found = detectCycle(head);
            cout << found << endl;
            if (found == true) {
                cout << "There is a cycle in the list" << endl;
            }
            else {
                cout << "There is No cycle in the list" << endl;
            }
            break;
        case 14:
            bool found2;
            found2 = detectCycle(head);
            cout << found2 << endl;
            if (found2 == true) {
                removeCycle(head);
            }
            else {
                cout << "There is No cycle in the list" << endl;
            }
            break;
        default:
            cout << "Command Not found" << endl;
            break;
        }
    }
    // cout << "Our linked list length is " << getLength(head) << endl;



    // print the linked list
    displayLinkedList(head);

    return 0;
}


/*
2 1 2 2 2 3 2 4 2 5 2 6 2 7 2 8 2 9 2 10

 */
