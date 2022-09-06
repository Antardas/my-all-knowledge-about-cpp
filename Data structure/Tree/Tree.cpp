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

void inOrderTraversal(TreeNode* root, string& str) { //  left root right
    if (root == NULL) return;
    inOrderTraversal(root->leftChild, str);
    str += to_string(root->data);
    inOrderTraversal(root->rightChild, str);
}
void preOrderTraversal(TreeNode* root, string& str) { //   root left right
    if (root == NULL) return;
    str += to_string(root->data);
    preOrderTraversal(root->leftChild, str);
    preOrderTraversal(root->rightChild, str);
}
void postOrderTraversal(TreeNode* root, string& str) { //  left  right root
    if (root == NULL) return;
    postOrderTraversal(root->leftChild, str);
    postOrderTraversal(root->rightChild, str);
    str += to_string(root->data);
}

void levelOrderTraversal(TreeNode* root, string str) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);


    while (!q.empty()) {
        TreeNode* checkNode = q.front();
        q.pop();
        if (checkNode != NULL) {
            cout << checkNode->data << " ";
            if (checkNode->leftChild != NULL) {
                q.push(checkNode->leftChild);
            }

            if (checkNode->rightChild != NULL) {
                q.push(checkNode->rightChild);
            }
        }
        else {
            if (!q.empty()) {
                q.push(NULL);
            }
        }
    }
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
    id;
    TreeNode* newNode = new TreeNode(current);
    if (start == end) {
        return newNode;
    }
    int pos = searchInOrder(inOrder, current, start, end);
    newNode->leftChild = buildTreePreIn(preOrder, inOrder, start, pos - 1);
    newNode->rightChild = buildTreePreIn(preOrder, inOrder, pos + 1, end);

    return newNode;
}

// Exam 8
bool is_same(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    queue<TreeNode*>q1;
    queue<TreeNode*>q2;
    q1.push(root1);
    q1.push(NULL);
    q1.push(root2);
    q1.push(NULL);

    bool same = true;
    while (!q1.empty() && !q2.empty()) {
        TreeNode* checkNode1 = q1.front();
        TreeNode* checkNode2 = q2.front();
        if (checkNode1 != NULL && checkNode2 == NULL) {

            if (checkNode1->data == checkNode2->data) {
                same = true;
                if (checkNode1->leftChild != NULL) {
                    q1.push(checkNode1->leftChild);
                }
                if (checkNode2->leftChild != NULL) {
                    q2.push(checkNode2->leftChild);
                }
                if (checkNode1->rightChild != NULL) {
                    q1.push(checkNode1->rightChild);
                }
                if (checkNode2->rightChild != NULL) {
                    q2.push(checkNode2->rightChild);
                }

            }
            else {
                same = false;
                return;
            }
        }
        else {
            if (!q1.empty() && !q2.empty()) {
                q1.push(NULL);
                q2.push(NULL);
            }
            return false;
        }

    }

}


int main() {

    int n;
    cout << "How many nodes you want to add : ";
    cin >> n;
    TreeNode* allNodes[n];

    for (int i = 0; i < n; i++) {
        allNodes[i] = new TreeNode(-1);
    }
    for (int i = 0; i < n; i++) {
        int val, left, right;
        cout << "value | " << "Left | " << "Right | ";
        cin >> val >> left >> right; // 0 1 2
        allNodes[i]->data = val;
        cout << n << endl;
        if (left > n - 1 || right > n - 1) {
            cout << "Invalid Index" << endl;
            break;
        }
        if (left != -1) { // Linking node / root / leaf
            allNodes[i]->leftChild = allNodes[left];
        }
        if (left != -1) { // Linking node / root / leaf
            allNodes[i]->rightChild = allNodes[right];
        }
    }


    // string inOrderTraversalStr = "";
    // string preOrderTraversalStr = "";
    // string postOrderTraversalStr = "";
    // string levelordertraversal = "";

    // inOrderTraversal(allNodes[0], inOrderTraversalStr);
    // preOrderTraversal(allNodes[0], preOrderTraversalStr);
    // inOrderTraversal(allNodes[0], postOrderTraversalStr);
    // levelOrderTraversal(allNodes[0], levelordertraversal);


    // cout << "In Order Traversal   : " << inOrderTraversalStr << endl;
    // cout << "Pre Order Traversal  : " << preOrderTraversalStr << endl;
    // cout << "Post Order Traversal : " << postOrderTraversalStr << endl;

    // printTree(allNodes[0], 0);

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
*/