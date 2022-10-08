#include <iostream>
using namespace std;
/*Create a node class/struct.
Create a queue class/struct.

Members:
Node - a node that tracks the front of the queue.
Node - a node that tracks the end of the queue.
Count - indicates how many items are on the queue.

Methods:
En-queue
- Accepts a number and adds to the end of the queue.
De-queue
- Returns a number from the front of the queue.
- If the queueis empty, emit an error indicating the queueis empty.
IsEmpty
- Returns a boolean indicating if the queue is empty.
*/

struct Node{
    int info;
    Node* nextNode;
    Node(int x){
        info = x;
        nextNode = NULL;
    }
};

struct Queue{
    Node *front, *back;
    Queue(){
        front = back = NULL;
    }

    bool isEmpty(){
        if (front == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    
    void enqueue(int x){
        Node* temp = new Node(x);
        if (back == NULL){
            front = back = temp;
            return;
        }
        back->nextNode = temp;
        back = temp;
    }

    void dequeue(){
        if (isEmpty()){
            puts("Queue is empty!!\n");
        }
        Node* temp = front;
        front = front->nextNode;

        if (front == NULL){
            back = NULL;
        }
        delete(temp);
    }
};

int main(){
    int count = 1;
    int choice;
    int value;
    Queue a;

    while (count == 1){
    cout << "Please choose what you would like to do:\n1.Enqueue\n2.Dequeue\n3.Exit\n";
    cin >> choice;

    switch (choice){
    case 1:
        cout << "Please enter the value you would like to enqueue:\n";
        cin >> value;
        a.enqueue(value); //adds
        break;
    case 2:
        a.dequeue(); //deletes
        break;
    case 3:
        count = 0;
        break;
    }
}
}