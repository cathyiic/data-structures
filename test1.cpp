#include <iostream>
using namespace std;

//question 2
Queue:: Dequeue(){
    //assume that we wrote a bool isEmpty function that works
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



//question 1
int FindLast(int numbers[], int size, int key, int occurence){
    int index = -1;
    int count = 0;
    for (int i = 0; i < size; i++){
        if (numbers[i] = key){
            count++;
            if (count == occurance){
                index = i;
                break;
            }
        }
        return index;
    }
}

