#include <iostream>
using namespace std;
#define MAXSIZE = 10;
/*Objective:  Create a sorted singly linked list of numbers based upon user input.

Program logic:
Ask for a number, add that number to the list in sorted position, print the list.
Repeat until they enter -1 for the number.
*/

struct Node{
    int x;
    Node *next;
};
struct Node *front, *back = NULL;

void addNode(int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->next = NULL;
    //for some reason cannot create the bool functions so i check the emptiness
    //and fullness here
    if(front == NULL){
        front = newNode;
        back = newNode;
    }
    else{
        back->next = newNode;
        back = newNode;
    }
}
void sortList(){
    //new updated node
    int temp;
    Node *update = front;
    Node *index = NULL;

    if (front == NULL){ //checks if list is empty
        cout << "The list is empty\n";
    }
    else{
        while (update != NULL){ //list isn't empty
            index = update->next; //index points next to the update

            while (index != NULL){
                if (update->x > index->x){ //if the updated value is greater, then switch (sorts it)
                    temp = update->x;
                    update->x = index->x;
                    index->x = temp;
                }
                index = index->next;
            }
            update = update->next;

            }
        }
}

void printList(){
    struct Node *update = front;
    //checks if list is empty
    if (front == NULL){
        cout << "The list is empty\n";
    }
    while(update != NULL){//not empty so it will print list
        cout << "%d\n", update->x;
        update = update->next;
    }
}

int main(){
    int choice;
    int looping = 1;
    int value;
    while (looping == 1){
    cout << "Please enter what you would like to do.\n1.Add to list\n2.Display list\n3.Sort List\n4.Exit\n";
    //instead of using -1 to exit, i just made it an option on the menu (option 4)
    cin >> choice;

    switch(choice){
        case 1:
            cout << "What integer would you like to add?\n";
            cin >> value;
            addNode(value);
            break;
        case 2:
            cout << "Displaying the list\n";
            printList();
            break;
        case 3:
            cout << "Sorting the list\n";
            sortList();
            break;
        case 4:
        looping = 0;
            break;
    }
}
}



