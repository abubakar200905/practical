#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Binary Search Tree Class
class BST {
private:
    Node* root;

    // Helper functions
    Node* insert(Node* node, int value) {
        if (node == nullptr) return new Node(value);
        if (value < node->data) 
            node->left = insert(node->left, value);
        else if (value > node->data) 
            node->right = insert(node->right, value);
        return node;
    }

    bool search(Node* node, int value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        if (value < node->data) 
            return search(node->left, value);
        return search(node->right, value);
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    int findDepth(Node* node) {
        if (node == nullptr) return 0;
        int leftDepth = findDepth(node->left);
        int rightDepth = findDepth(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    void displayLeafNodes(Node* node) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            cout << node->data << " ";
        }
        displayLeafNodes(node->left);
        displayLeafNodes(node->right);
    }

public:
    // Constructor
    BST() { root = nullptr; }

    // Public Methods
    void insert(int value) { root = insert(root, value); }

    bool search(int value) {
        return search(root, value);
    }

    void displayTree() {
        cout << "\nIn-order Traversal: ";
        inorder(root);
        cout << "\nPre-order Traversal: ";
        preorder(root);
        cout << "\nPost-order Traversal: ";
        postorder(root);
    }

    void displayDepth() {
        cout << "\nDepth of the Tree: " << findDepth(root) << endl;
    }

    void displayLeafNodes() {
        cout << "Leaf Nodes: ";
        displayLeafNodes(root);
        cout << endl;
    }
};

// Main Function
int main() {
    BST tree;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Search Element\n";
        cout << "3. Display Tree (Traversals)\n";
        cout << "4. Display Depth of Tree\n";
        cout << "5. Display Leaf Nodes\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                cout << value << " inserted successfully.\n";
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value))
                    cout << value << " found in the tree.\n";
                else
                    cout << value << " not found.\n";
                break;
            case 3:
                tree.displayTree();
                break;
            case 4:
                tree.displayDepth();
                break;
            case 5:
                tree.displayLeafNodes();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
