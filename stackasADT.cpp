#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
using namespace std;

// Define the Node structure for Stack
struct Node {
    char data;
    Node* next;
};

// Stack ADT using Singly Linked List
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push element onto the stack
    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Pop element from the stack
    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        Node* temp = top;
        char value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    // Peek the top element
    char peek() {
        if (isEmpty()) {
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to determine operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {  // Operand (characters)
            postfix += c;
        } else if (c == '(') {  // Left parenthesis
            s.push(c);
        } else if (c == ')') {  // Right parenthesis
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop();  // Remove '(' from stack
        } else if (isOperator(c)) {  // Operator
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    Stack s;

    for (char c : postfix) {
        if (isalnum(c)) {  // Operand (characters)
            s.push(c);
        } else if (isOperator(c)) {  // Operator
            char b = s.pop();
            char a = s.pop();

            // Perform the operation on characters
            int result;
            switch (c) {
                case '+': result = (a - '0') + (b - '0'); break;
                case '-': result = (a - '0') - (b - '0'); break;
                case '*': result = (a - '0') * (b - '0'); break;
                case '/': result = (a - '0') / (b - '0'); break;
                case '^': result = pow((a - '0'), (b - '0')); break;
                default: result = 0;
            }

            // Push result as a character
            s.push(result + '0');
        }
    }

    // Return final result
    return s.pop() - '0';  // Convert char back to int
}

// Main Function
int main() {
    string infix;
    cout << "Enter infix expression (using characters): ";
    cin >> infix;

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    // Evaluate postfix expression
    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
