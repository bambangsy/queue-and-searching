#include <iostream>
#include <cstdlib>


using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char value) {
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

    void enqueue(char value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot perform dequeue operation." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot perform peek operation." << endl;
            return char();
        }

        return front->data;
    }

    void display() {
        Node* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

void createZumaBalls(Queue& zumaBalls, int numBalls) {

    char colors[] = {'R', 'G', 'B', 'Y'}; // Possible ball colors

    for (int i = 0; i < numBalls; ++i) {
        int randomIndex = rand() % 4; // Generate a random index between 0 and 3
        char ballColor = colors[randomIndex]; // Get a random ball color

        zumaBalls.enqueue(ballColor); // Enqueue the ball color to the Zuma balls
    }
}

void shootBall(Queue& zumaBalls) {
    char ballColor = zumaBalls.peek();
    zumaBalls.dequeue();
    int randomIndex = rand() % 4;
	char newBallColor = "RGBY"[randomIndex];
    zumaBalls.enqueue(newBallColor);

    cout << "Shot Zuma Ball: " << ballColor << endl;
}

int main() {
    Queue zumaBalls;

    createZumaBalls(zumaBalls, 10); // Create 10 random Zuma balls


    char choice;
    while (true) {
    	zumaBalls.display();
        cout << "Press 1 to shoot a Zuma ball (or any other key to exit): ";
        cin >> choice;

        if (choice == '1') {
            shootBall(zumaBalls);
            system("pause");
            system("cls");
        } else {
            break;
        }
        
    }

    return 0;
}
