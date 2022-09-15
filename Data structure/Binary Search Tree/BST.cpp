#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int value) {
        this->data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};


void inOrderTraversal(TreeNode* root, string& output) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->leftChild, output);
    output += to_string(root->data) + ' ';
    inOrderTraversal(root->rightChild, output);
}



// Insert Binary search tree
TreeNode* insertionBST(TreeNode* root, int value) {
    TreeNode* newNode = new TreeNode(value);
    if (root == NULL) {
        root = newNode;
        return root;
    }

    // IF VALUE < ROOT->VALUE THEN
    if (value < root->data) {
        root->leftChild = insertionBST(root->leftChild, value);
    }
    else if (value > root->data) {
        root->rightChild = insertionBST(root->rightChild, value);
    }
    return root;
}

// 
TreeNode* searchBST(TreeNode* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == value) {
        return root;
    }

    else if (root->data > value) {
        searchBST(root->leftChild, value);
    }
    else {
        searchBST(root->rightChild, value);

    }
}

TreeNode* inOrderSuccessor(TreeNode* root, int value) {
    TreeNode* currentNode = root;


    while (currentNode->leftChild != NULL && currentNode != NULL) {
        currentNode = currentNode->leftChild;
    }
    return currentNode;
}

// 

TreeNode* deleteBST(TreeNode* root, int value) {
    if (value < root->data) {
        root->leftChild = deleteBST(root->leftChild, value);
    }
    else if (value > root->data) {
        root->rightChild = deleteBST(root->rightChild, value);
    }
    else { // when it's finally get value
        if (root->leftChild == NULL) {
            TreeNode* tempNode = root->rightChild;
            free(root);
            return tempNode;
        }
        else if (root->rightChild == NULL) {
            TreeNode* tempNode = root->leftChild;
            free(root);
            return tempNode;
        }
        else {
            TreeNode* tempNode = inOrderSuccessor(root, value);
            root->data = tempNode->data;
            tempNode->rightChild = deleteBST(root->rightChild, tempNode->data);
        }

        return root;
    }
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = insertionBST(root, value);
    }
    string output;
    inOrderTraversal(root, output);

    cout << endl << endl << output << endl;
    int key;
    cout << "Enter the you want to search : ";
    cin >> key;
    TreeNode* foundNode = searchBST(root, key);
    if (foundNode == NULL) {
        cout << "doesn't exit this BST" << endl;
    }
    else {
        cout << "Value is exist in this BST" << endl;
    }

    cout << "Enter the value you want to Delete : ";
    cin >> key;
    TreeNode* deletedNode = deleteBST(root, key);
    output = "";
    inOrderTraversal(root, output);

    cout << endl << endl << output << endl;

    return 0;
}


/*
17
25 20 36 10 22 30 40 5 12 28 38 48 1 8 15 45 50


9
11 5 9 43 34 1 2 7 21
 */