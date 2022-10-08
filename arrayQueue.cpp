#include <iostream>
using namespace std;
#define MAXSIZE 10
/*Create a class/struct.

Members:
MaxSize const = 10
Define an array that holds 10 items.
Count - indicates how many items are on the queue.
Front - where the front of the queue is in the array. 
Back - Where the end of the queue is in the array. 


Methods:
En-queue
- Accepts a number and adds to the end of the queue.
- If the queue is full emit an error indicating full.
De-queue
- Returns a number from the front of the queue.
- If the queueis empty, emit an error indicating the queueis empty.
IsEmpty
- Returns a boolean indicating if the queue is empty.
*Note that the front and back can wrap around the end of the array over time. 
*/
//code would not work if I made a struct or class for some reason :(
/*
int front, back = 0;
int arr1[MAXSIZE];

bool isEmpty(){
        if (front == 0 && back == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
void enqueue(int info){
    if (back == MAXSIZE-1){
        puts("Queue is full\n");
        return;
    }
    else{
        if (front == 0){ //adds
            front = 1;
            back++;
            arr1[back] = info;
        }
    }
}

void dequeue(){
    if (isEmpty()){
        puts("Queue is empty\n");
    } 
    else{ //shifts the values in the queue
        if (front == back){
            front = back = 0;
        }
        else {
            front++;
        }
    }
}

int main(){
    int count = 1;
    int choice;
    int value;

    while (count == 1){
    cout << "Please choose what you would like to do:\n1. Enqueue\n2.Dequeue\n3.Exit\n";
    cin >> choice;

    switch (choice){
    case 1:
        cout << "Please enter the value you would like to enqueue:\n";
        cin >> value;
        enqueue(value); //adds
        break;
    case 2:
        dequeue(); //deletes
        break;
    case 3:
        count = 0;
        break;
    }
}
}
*/
//rewrote the code for partial credit 
class Queue{
    public:
    int arr1[MAXSIZE];
    int front, back;

    Queue(){
        front = -1;
        back = -1;
    }

    bool isEmpty(){ //for dequeue 
        if (front == -1 && back == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){ //for enqueue
        if ((back + 1) % MAXSIZE == front){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int value){
        if (isFull()){
            cout << "The queue is full\n";
        }
        else if (isEmpty()){
            front = back = 0;
            cout << "The queue is empty, proceed\n";
        }
        else{
            back = (back + 1) % MAXSIZE;
        }
        arr1[back] = value; //adds value to end
    }

    void dequeue(){ //removes value in queue
        if (isEmpty()){
            cout << "The queue is empty\n";
        }
        else if (front == back){
            back = front = -1;
        }
        else {
            front = (front + 1) % MAXSIZE;
        }
    }

    void printQueue(){
        int count = (back + MAXSIZE - front) % MAXSIZE;
        for (int i = 0; i < count; i++){
            int index = (front + i) % MAXSIZE;
            cout << arr1[index] << " \n";
        }
    }
};

int main(){
    Queue one;
    one.enqueue(2);
    one.dequeue();
    one.enqueue(4);
    one.enqueue(3);
    one.enqueue(8);
    one.dequeue();
    one.printQueue();
}