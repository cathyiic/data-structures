#include <iostream>
using namespace std;
/*Create a class/struct for a node.
Create a class/struct for a list.

Members:
Top - a node that tracks the top of the stack
Count - indicates how many items are on the stack.

Methods:
Push
- Accepts a number and adds to the top of the stack.
Pop
- Returns a number from the top of the stack.
- If the stack is empty, emit an error indicating the stack is empty.
IsEmpty
- Returns a boolean indicating if the stack is empty.
*/
struct Node{ //struct for a node
    int info;
    struct Node *nextValue;
};

Node *top = NULL;

void push(int num){ //push method
    Node *newNode = new Node();
    newNode->info = num;
    newNode->nextValue = top;
    top = newNode;
}

bool isEmpty(){ //makes sense to use isEmpty before pop method
    if (top == NULL){
        return true;
    }
    else{
        return false;
    }
}

void pop(){ //pop method
    if (isEmpty()){
        cout << "Empty!\n";
    }
    else{
    Node *newNode = top;
    top = top->nextValue;
    delete(newNode);
    }
}

int main(){
    int choice, value;
    int count = 1;
    
    while (count == 1){
        cout << "Please enter what you would like to do:\n1.Push\n2.Pop\n3.Exit\n";
        cin >> choice;

        switch (choice){
        case 1:
        cout << "Please enter the value you would like to push\n";
        cin >> value;
        push(value);
        break;
        case 2:
        pop();
        break;
        case 3:
        count = 0;
        break;
    }    
    }
}
