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


int main() {
    int n;
    cin >> n;
    int arr[n];
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Value : ";
        cin >> value;
        root = insertionBST(root, value);
    }
    string output;
    inOrderTraversal(root, output);

    cout << endl << endl << output << endl;
    int searchValue;
    cout << "Enter the you want to search : ";
    cin >> searchValue;
    TreeNode* foundNode = searchBST(root, searchValue);
    if (foundNode == NULL) {
        cout << "doesn't exit this BST" << endl;
    }
    else {
        cout << "Value is exist in this BST";
    }
    return 0;
}


/*
17
25 20 36 10 22 30 40 5 12 28 38 48 1 8 15 45 50


9
11 5 9 43 34 1 2 7 21
 */