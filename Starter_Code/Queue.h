// Queue.h
// ESE 224 Fall 2026 Final Project (Part II) starter code
// Team members: Shushana
//
// A first-in first-out queue built on your own singly linked list (Section 4.1).
// Templates must be written entirely in the header file.


#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* frontPtr;   // Oldest Item
    Node* rearPtr;    // Newest Item
    int count;        // # of elements in the queue

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr), count(0) {}

    // clear remianing nodes to prevent memory leaks
    ~Queue() {
        clear();
    }

    // Disable copying 
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    // This function appends a copy of an item to the back of the quueu
    void enqueue(const T& item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            frontPtr = newNode;
            rearPtr = newNode;
        } else {
            rearPtr-> next = newNode;
            rearPtr = newNode;
        }
        count++;
    }

    // This function removes the front item into item and returns false if empty
    bool dequeue(T& item) {
        if (isEmpty()) {
            return false;
        }
        Node* temp = frontPtr;
        item = frontPtr->data;
        frontPtr = frontPtr->next;
        if (frontPtr == nullptr) {
            rearPtr= nullptr;
        }
        delete temp;
        count--;
        return true;
    }

    // This function copies the front item into item without removing it and returns false if empty
    bool front(T& item) const {
        if (isEmpty()) {
            return false;
        }
        item = frontPtr->data;
        return true;
    }

    // This function returns true when there are no elements in the queue
    bool isEmpty() const {
        return count == 0;
    }

    // returns $ of elements in the queue
    int size() const {
        return count;
    }

    // Removes + delets every node in the queue
    void clear() {
        T dummy;
        while (dequeue(dummy)) {}
    }
};

#endif