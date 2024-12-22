#include "stack.h"
#include <iostream>

using namespace std;

// Constructor to initialize the stack
template <typename T>
Stack<T>::Stack() : top(nullptr) {}

// Destructor to clean up the stack
template <typename T>
Stack<T>::~Stack() {
    deleteStack();
}

// Push a value onto the stack
template <typename T>
void Stack<T>::push(const T& value) {
    Node* newNode = new Node{ value, top };  // Create a new node and push it to the top
    top = newNode;  // Make the new node the top of the stack
}

// Pop a value from the stack
template <typename T>
void Stack<T>::pop() {
    if (top != nullptr) {
        Node* temp = top;
        top = top->next;  // Move the top pointer to the next node
        delete temp;      // Delete the popped node
    }
}

// Get the value at the top of the stack
template <typename T>
T Stack<T>::topValue() const {
    if (top != nullptr) {
        return top->data;  // Return the data of the top node
    }
    return T();  // Return a default-constructed value of type T if the stack is empty
}

// Check if the stack is empty
template <typename T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;  // Return true if the stack is empty
}

// Function to delete the stack (free memory)
template <typename T>
void Stack<T>::deleteStack() {
    Node* current = top;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    top = nullptr;
}

template class Stack<std::string>;
template class Stack<int>;
template class Stack<double>;
