#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Enqueued element: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot perform dequeue operation." << endl;
            return;
        }

        Node* temp = front;
        int dequeuedElement = temp->data;
        front = front->next;
        delete temp;

        cout << "Dequeued element: " << dequeuedElement << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot perform peek operation." << endl;
            return -1;
        }

        return front->data;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    
}

