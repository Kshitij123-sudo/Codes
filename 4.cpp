4 practical problem statement : Beginning with an empty binary search reconstruct binary search tree by inserting the values in order given after constructing a binary tree first insert new node second 
Find a number of nodes in longest path from route 3rd minimum data value found in tree 4th changer tree so that the roles of the left and right pointer are swapped At every node fifth search a value. 
Keep the code very simple and easy to understand write a small algorithm for it 



#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to insert a node in BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Function to find longest path from root (height of tree)
int longestPath(Node* root) {
    if (root == NULL)
        return 0;
    int left = longestPath(root->left);
    int right = longestPath(root->right);
    return max(left, right) + 1;
}

// Function to find minimum value in BST
int findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

// Function to mirror the tree
void mirror(Node* root) {
    if (root == NULL)
        return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

// Function to search a value in BST
bool search(Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Inorder display
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main function
int main() {
    Node* root = NULL;
    int n, val;
    
    cout << "Enter number of elements to insert: ";
    cin >> n;
    
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nLongest path from root (height): " << longestPath(root);
    cout << "\nMinimum value in BST: " << findMin(root);

    mirror(root);
    cout << "\nInorder after mirroring tree: ";
    inorder(root);

    cout << "\nEnter value to search: ";
    cin >> val;
    if (search(root, val))
        cout << val << " found in BST.\n";
    else
        cout << val << " not found in BST.\n";

    return 0;
}





✅ Simple Algorithm: Binary Search Tree Operations
Start

Create a Node class with:

data value

left and right pointers

Insert values into BST one by one using insert function.

Find the longest path from root to a leaf and count the number of nodes.

Find the minimum value in the BST by going to the leftmost node.

Mirror the tree (swap left and right at every node using recursion).

Search for a value using BST search logic.

Stop
