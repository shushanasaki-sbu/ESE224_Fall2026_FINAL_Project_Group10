// Stack.h
// ESE 224 Fall 2026 Final Project (Part II) starter code
// Team members: Shushana
//
// A last-in first-out stack built on your own singly linked list (Section 4.1).
// Templates must be written entirely in the header file.
// Stack.h


#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n) : data(d), next(n) {}
    };

    Node* topPtr;   // Top of the stack
    int count;     // # of elements on stack

public:
    Stack() : topPtr(nullptr), count(0) {}

    // clear remaining nodes to prevent memory leaks
    ~Stack() {
        clear();
    }

    // disable copying
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    // This function pushes a new node containing item onto the top of the stack
    void push(const T& item) {
        Node* newNode= new Node(item, topPtr);
        topPtr = newNode;
        count++;
    }

    // This function pops the top item into item and returns false if the stack is empty
    bool pop(T& item) {
        if (isEmpty()) {
            return false;
        }
        Node* temp = topPtr;
        item = topPtr -> data;
        topPtr = topPtr->next;
        delete temp;
        count--;
        return true;
    }

    // This function copies the top item into item without remving and returns false if the stack if empty
    bool top(T& item) const {
        if (isEmpty()) {
            return false;
        }
        item = topPtr->data;
        return true;
    }

    // This function returns true if the stack has no elements
    bool isEmpty() const {
        return count == 0;
    }

    // returns # of elements on stack
    int size() const {
        return count;
    }

    // removes each node on stack
    void clear() {
        T dummy;
        while (pop(dummy)) {}
    }
};

#endif