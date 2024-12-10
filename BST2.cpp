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

    Node* minValueNode(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return node;

        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else {
            // Node with one or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
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

public:
    // Constructor
    BST() { root = nullptr; }

    // Public Methods
    void insert(int value) { root = insert(root, value); }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    void displayTree() {
        cout << "\nIn-order Traversal: ";
        inorder(root);
        cout << "\nPre-order Traversal: ";
        preorder(root);
        cout << "\nPost-order Traversal: ";
        postorder(root);
    }
};

// Main Function
int main() {
    BST tree;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display Tree (Traversals)\n";
        cout << "4. Exit\n";
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
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteValue(value);
                cout << value << " deleted (if found).\n";
                break;
            case 3:
                tree.displayTree();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
