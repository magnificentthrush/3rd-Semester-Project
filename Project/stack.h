#ifndef STACK_H
#define STACK_H

template <typename T>  // Declare a template with type T
class Stack {
private:
    struct Node {
        T data;  // Data can be of any type T
        Node* next;
    };

    Node* top;  // The top of the stack

public:
    // Constructor to initialize the stack
    Stack();

    // Destructor to clean up the stack
    ~Stack();

    // Push a value onto the stack
    void push(const T& value);

    // Pop a value from the stack
    void pop();

    // Get the value at the top of the stack
    T topValue() const;

    // Check if the stack is empty
    bool isEmpty() const;

    // Function to delete the stack (free memory)
    void deleteStack();
};

#endif // STACK_H
