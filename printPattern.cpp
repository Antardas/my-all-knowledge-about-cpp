#include<bits/stdc++.h>

using namespace std;

int x = 0;
class Node {  //In the class of node setting the value and the address of the next node

public:
    int value;
    Node* Next;

    // Constructor Creation
    Node(int val) //initialising the Node
    {
        cout << "Calling Constructor function : " << x++ << endl;
        value = val; // In the constructor value will be the val
        Next = NULL; // and the Next will be NULL
    }

};

void insertAtTail(Node*& head, int val) //sending in the variable of pointer var and int val
{
    Node* newNode = new Node(val);   // 1 | add -> 5 | add  //creating new node // instance create

    if (head == NULL) //Case - 1 if head is equal Null
    {
        head = newNode; //then head is the new node
        return;
    }
    Node* temp = head;  //head is kept to a temp

    while (temp->Next != NULL)  //till The next add will be null
    {
        temp = temp->Next; //there will be creating space for NEXT address
    }
    temp->Next = newNode; //and the NEXT ADD Will be new node
}

void insertAtHead(Node*& head, int val)
{

    //s1 : newNode creation
    Node* newNode = new Node(val);
    //s2 : Update of newNode -> Next
    newNode->Next = head;
    //s3 : Update of head
    head = newNode;
}
void display(Node* n)
{

    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " -> ";
        n = n->Next;
    }
    cout << endl << endl;
}


int main()
{
    Node* head = new Node(12);

    int value;
    cout << "Choice 1: Insertion at Head" << endl
        << "Choice 2: Insertion at Tail" << endl
        << "Choice 0: Exit" << endl
        << endl;

    cout << "Next Choice: ";
    int choice;
    cin >> choice;

    while (choice != 0)
    {
        cout << "Enter the Value: ";
        cin >> value;
        if (choice == 1)
            insertAtHead(head, value);
        else if (choice == 2)

            insertAtTail(head, value);

        cout << "Next Choice: ";
        cin >> choice;
    }

    display(head);

    return 0;
}


