#include <bits/stdc++.h>

using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int val) {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }

};

void printSpace(int level) {
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
}

void printTree(TreeNode* root, int level) {
    if (root == NULL) return; //  we was sent first element because it's a main root 
    if (root->leftChild == NULL && root->rightChild == NULL) {
        cout << root->data << endl;
        return;
    }
    else {
        cout << endl;
        printSpace(level);
        cout << "Root  : " << root->data << endl;
    }
    if (root->leftChild != NULL) {
        printSpace(level);
        cout << "Left  : ";
        printTree(root->leftChild, level + 1);
    }
    if (root->rightChild != NULL) {
        printSpace(level);
        cout << "Right : ";
        printTree(root->rightChild, level + 1);
    }

}

void preOrderTraversal(TreeNode* root, string& str) { //   root left right
    if (root == NULL) return;
    str += to_string(root->data);
    preOrderTraversal(root->leftChild, str);
    preOrderTraversal(root->rightChild, str);
}

void levelOrderTraversal(TreeNode* root) {

}

int searchInOrder(int inOrder[], int current, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (inOrder[i] == current) {
            return i;

        }
    }
    return -1;
}

TreeNode* buildTreePreIn(int preOrder[], int inOrder[], int start, int end) {
    static int id = 0;
    int current = preOrder[id];
    id++;
    TreeNode* newNode = new TreeNode(current);
    if (start == end) {
        return newNode;
    }
    int pos = searchInOrder(inOrder, current, start, end);
    newNode->leftChild = buildTreePreIn(preOrder, inOrder, start, pos - 1);
    newNode->rightChild = buildTreePreIn(preOrder, inOrder, pos + 1, end);

    return newNode;
}

int main() {

    int n;
    cout << "How many nodes you want to add : ";
    cin >> n;
    int preOrder[n], inOrder[n];
    for (int i = 0; i < n; i++) {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> inOrder[i];
    }

    TreeNode* root = buildTreePreIn(preOrder, inOrder, 0, n - 1);
    string check;
    preOrderTraversal(root, check);

    cout << endl << check << endl;





}

/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

Root  : 0
Left  :
   Root  : 1
   Left  : 3
   Right : 4
Right :
   Root  : 2
   Left  :
      Left  : 7
      Right : 8
   Right : 6

In Order Traversal   : 314075826
Pre Order Traversal  : 013425786
Post Order Traversal : 314075826


9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6
*/