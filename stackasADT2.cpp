#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// Node structure for Stack
struct Node {
    char data;
    Node* next;
};

// Stack class using Singly Linked List
class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    // Stack Operations
    void push(char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return '\0';
        }
        Node* temp = top;
        char value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    char peek() {
        if (!isEmpty())
            return top->data;
        return '\0';
    }

    bool isEmpty() { return top == nullptr; }
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to get precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    Stack s;
    string prefix;
    reverse(infix.begin(), infix.end());

    for (char& c : infix) {
        if (isalnum(c)) // If the character is an operand
            prefix += c;
        else if (c == ')')
            s.push(c);
        else if (c == '(') {
            while (!s.isEmpty() && s.peek() != ')')
                prefix += s.pop();
            s.pop();
        } else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
                prefix += s.pop();
            s.push(c);
        }
    }

    while (!s.isEmpty())
        prefix += s.pop();

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

// Function to evaluate prefix expression
int evaluatePrefix(string prefix) {
    Stack s;
    reverse(prefix.begin(), prefix.end());

    for (char& c : prefix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else if (isOperator(c)) {
            int op1 = s.pop();
            int op2 = s.pop();

            switch (c) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': s.push(op1 / op2); break;
                case '^': s.push(pow(op1, op2)); break;
            }
        }
    }
    return s.pop();
}

// Main Function
int main() {
    string infix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    int result = evaluatePrefix(prefix);
    cout << "Result after Evaluation: " << result << endl;

    return 0;
}
