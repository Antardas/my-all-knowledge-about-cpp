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

// Exam 8 we can solve this problem
/*
    1. using levelByTraversal method first get all node value 1st tree then 2nd after we can match that string.

 */
 // Ans 1
bool is_same_tree(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    if (root1 != NULL && root2 != NULL) {
        root1->data == root2->data
            && is_same_tree(root1->leftChild, root2->leftChild)
            && is_same_tree(root1->rightChild, root2->rightChild);
    }

    return false;

}

// Ans 2
void level_order(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*>q;
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


// Ans 3
void level_order_reverse(TreeNode* root) {
    if (root == NULL) return;
    string str = "";
    queue<TreeNode*>q;
    stack<int>st;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode* checkNode = q.front();
        q.pop();
        if (checkNode != NULL) {
            // cout << checkNode->data << endl;
            st.push(checkNode->data);
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
    int first;
    int second;
    while (!st.empty())
    {
        first = st.top();
        st.pop();
        if (!st.empty()) {
            second = st.top();
            cout << second << " ";
            st.pop();
        }
        cout << first << " ";
    }

}


// Ans 4

bool checkMirror(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }


    if (root1 && root2 && root1->data == root2->data) {
        return checkMirror(root1->leftChild, root2->rightChild) && checkMirror(root1->rightChild, root2->leftChild);
    }
    return false;
}
bool isSymmetric(TreeNode* root) {
    return checkMirror(root, root);
}

// Ans 5

void zig_zag_order(TreeNode* root) {
    if (root == NULL) return;
    string str = "";
    queue<TreeNode*>q;
    queue<int>st;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode* checkNode = q.front();
        q.pop();
        if (checkNode != NULL) {
            // cout << checkNode->rightChild->data << " ";
            // cout << checkNode->data << " ";
            st.push(checkNode->data);
            if (checkNode->rightChild != NULL) {
                q.push(checkNode->rightChild);
            }
            if (checkNode->leftChild != NULL) {
                q.push(checkNode->leftChild);
            }
            // cout << checkNode->rightChild->data << " " << checkNode->leftChild->data << " ";

        }
        else {
            if (!q.empty()) {
                q.push(NULL);
            }
        }
    }
    while (!st.empty()) {
        cout << st.front() << " ";
        st.pop();
    }

}

// Ans 6
TreeNode* invert_tree(TreeNode* root) {
    if (root != NULL) {

        swap(root->leftChild, root->rightChild);
        invert_tree(root->leftChild);
        invert_tree(root->rightChild);
    }
    return root;

    /*
if (root != NULL) {
        swap(root->leftChild, root->rightChild);
        root->leftChild = invert_tree(root->leftChild);
        root->rightChild = invert_tree(root->rightChild);
    }
    return root;


     */
}

// Ans 7

int getAllNodesValue(TreeNode* root, int* sum) {

    //steps
    if (root == NULL) return 0;
    int leftValue = getAllNodesValue(root->leftChild, sum);
    int rightValue = getAllNodesValue(root->rightChild, sum);
    *sum += abs(leftValue - rightValue);

    return leftValue + rightValue + root->data;


}

int findTilt(TreeNode* root) {
    int sum = 0;
    getAllNodesValue(root, &sum);
    return sum;
}

// Ans 8

void average_level(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode*>q;

    q.push(root);
    while (!q.empty()) {
        int sum = 0, totalElement = 0;
        queue<TreeNode*> temp;
        while (!q.empty()) {
            TreeNode* checkNode = q.front();
            q.pop();
            sum += checkNode->data;
            totalElement++;
            if (checkNode->leftChild != NULL) {
                temp.push(checkNode->leftChild);
            }
            if (checkNode->rightChild != NULL) {
                temp.push(checkNode->rightChild);
            }
        }
        q = temp;
        cout << (sum * 1.0 / totalElement) << " ";
    }
}

// Ans 9:

bool is_unival(TreeNode* root) {
    if (!root) {
        return true;
    }



    if (root->rightChild != NULL
        && root->data != root->leftChild->data)
        return false;

    if (root->rightChild != NULL
        && root->data != root->rightChild->data)
        return false;

    return is_unival(root->leftChild)
        && is_unival(root->rightChild);
}



vector<int> ans;


void traverseTree(TreeNode* root)
{
    if (root != NULL) {
        traverseTree(root->leftChild);
        ans.push_back(root->data);
        traverseTree(root->rightChild);
    }
}

int second_minimum(TreeNode* root)
{
    traverseTree(root);

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] != ans[i + 1]) {
            return ans[i + 1];
        }
    }
    return -1;
}



int main() {

    int n, j;
    cout << "How many nodes you want to add : ";
    cin >> n;
    // cin >> j;
    TreeNode* allNodes[n];
    // TreeNode* allNodes2[j];

    for (int i = 0; i < n; i++) {
        allNodes[i] = new TreeNode(-1);
    }
    // for (int i = 0; i < 7; i++) {
    //     allNodes2[i] = new TreeNode(-1);
    // }
    for (int i = 0; i < n; i++) {
        int val, left, right;
        // cout << "value | " << "Left | " << "Right | ";
        cin >> val >> left >> right; // 0 1 2
        allNodes[i]->data = val;
        // cout << n << endl;
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

    // cout << "Enter Tree 2 Value" << endl;
    // for (int i = 0; i < j; i++) {
    //     int val, left, right;
    //     // cout << "value | " << "Left | " << "Right | ";
    //     cin >> val >> left >> right; // 0 1 2
    //     allNodes2[i]->data = val;
    //     cout << j << endl;
    //     if (left > n - 1 || right > n - 1) {
    //         cout << "Invalid Index" << endl;
    //         break;
    //     }
    //     if (left != -1) { // Linking node / root / leaf
    //         allNodes2[i]->leftChild = allNodes2[left];
    //     }
    //     if (left != -1) { // Linking node / root / leaf
    //         allNodes2[i]->rightChild = allNodes2[right];
    //     }
    // }


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
    // level_order(allNodes[0]);

    printTree(allNodes[0], 0);
    // cout << is_same_tree(allNodes[0], allNodes2[0]);
    // printTree(allNodes2[0], 0);
    // level_order_reverse(allNodes[0]); // Have change some logic
    TreeNode* mainRoot = invert_tree(allNodes[0]);
    // cout << "After invert tree ---------------------";
    // printTree(mainRoot, 0);
    // cout << "Symantric:  " << isSymmetric(allNodes[0]) << endl;
    // if (isSymmetric(allNodes[0]))
    //     cout << "Symmetric";
    // else
    //     cout << "Not symmetric";
    // return 0;

    // cout << "Find Tilt" << findTilt(allNodes[0]->rightChild) << endl;
    average_level(allNodes[0]);





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


-------

9
1 1 2
2 3 4
3 5 6
4 -1 -1
5 -1 -1
6 -1 -1
7 -1 7
8 8 -1
9 -1 -1

-----------
5
3 1 2
9 -1 -1
20 3 4
15 -1 -1
7 -1 -1


---------

7
1 1 2
2 3 4
2 5 6
3 -1 -1
4 -1 -1
4 -1 -1
3 -1 -1

---------

5
1 1 2
2 -1 3
2 -1 4
3 -1 -1
3 -1 -1


____________

7
1 1 2
2 3 4
2 5 6
3 -1 -1
4 -1 -1
4 -1 -1
4 -1 -1
_________

7
4 1 2
2 3 4
7 5 6
1 -1 -1
3 -1 -1
6 -1 -1
9 -1 -1

________

6
4 1 2
2 3 4
9 -1 5
3 -1 -1
5 -1 -1
7 -1 -1
________

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
3 3
0 1 2
1 -1 -1
2 -1 -1
0 1 2
1 -1 -1
2 -1 -1

*/