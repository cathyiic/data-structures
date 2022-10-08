#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
Program Specification:
1. Read data for names and weights for 15 people from the console where there is a name on a line followed by a weight on the next line, like in names.txt.
2. Your program will build a list for the data maintained in ascending order based on both name and weight via a doubly linked list.
3. This dll will use one pointer to keep weights in sorted order, and use the other link to keep names on sorted order.
4. You need to build the list as you go maintaining this ordering, so at any time a print method was called it would print the related field in order. (This means nodes are added to the list in sorted order, elements are not added to the list followed by a sort called on the list.)

For example after 3 elements are added for (Name – Weight):
Michael – 275, Tom – 150, Abe – 200.

Output:
Names & weights sorted(ascending) by name. : Abe – 200, Michael – 275, Tom - 150
Names & weights sorted(ascending) by weight. : Tom – 150, Abe – 200, Michael - 275
*/
//Credits: Referenced to geeksforgeeks.org website (https://www.geeksforgeeks.org/insertion-sort-doubly-linked-list/)
//for some help with implementation of the dll

//node of a doubly linked list
struct Node{
    int data;
    char name[20];
    int weight;

    Node *nextNode, *previous; 
};
Node *head, *tail, *origin, *a, *b, *c = NULL;
int counter = 0;

//create and return a new node of a dll
struct Node* getNode(int data)
{
    //allocate node
    struct Node* newNode =
          (struct Node*)malloc(sizeof(struct Node));
 
    //put in the data
    newNode->data = data;
    newNode->previous = newNode->nextNode = NULL;
    return newNode; 
}

void calc(int x){
    c = new Node;
    c->weight = x;
    c->nextNode = NULL;
    c->previous = NULL;
    if (counter == 0){ //sets the fields then adds the count
        head = c;
        tail = c;
        a = head;
        a->nextNode = NULL;
        a->previous = NULL;
        counter++;
    }
    else{
        a = head;
        b = a;
        if (c->weight < a->weight){
            c->nextNode = a;
            a->previous = c;
            c->previous = NULL;
            head = c;
            a = head;
            do{ 
                a = a->nextNode;
            } while (a->nextNode != NULL); //if not empty set to new node
            tail = a;
        }
        else if (c->weight > a->weight){
            while (a != NULL && c->weight > a->weight){
                b = a;
                a = a->nextNode;
                if (a == NULL){ //if nothing then assign
                    b->nextNode = c;
                    c->previous = b;
                    c->nextNode = NULL;
                    tail = c;
                    break; 
                }
                else if(c->weight < a->weight){
                    b->nextNode = c;
                    c->previous = b;
                    c->nextNode = a;
                    a->previous = c;
                    if (a->nextNode != NULL){ //if not empty then set to new node
                        do{
                            a = a->nextNode;
                        } while (a->nextNode != NULL);
                        tail = a;
                        break;
                    }
                }
            }
        }
    }
}

//function when traversing for the dll
void traversingHead(){
    Node *h = head;
    while (h != NULL){ 
        cout << h->weight << " " << endl; //points to the new weight and sorts
        h = h->nextNode;
    }
    cout << endl;
}

//function to print the ddl
void print(){
    Node *temp;
    temp = origin;
    //will go from the head's pointer and loop
        while (temp != NULL){
            cout << "Names & weights sorted (ascending) by name : \n";
            cout << "Name : " << temp->name << endl;
            cout << "Weight : " << temp->weight << endl;
            cout << "Names & weights sorted (ascending) by weight : \n";
            cout << endl;
            temp = temp->nextNode;
        }
}

int main(){
    int num, x;
    int counts = 0;
    char names;
    cout << "Please enter how many people :  \n";
    cin >> num;
    
    while (counts < num){
        cout << "Please enter the weights of the people : \n";
        cin >> x; //takes the input data of user
        calc(x); //calls calc function to calculate
        counts++;
    }
    cout << "Output of the weights sorted in ascending order: \n";
    traversingHead(); //calls function to traverse values
    print(); //calls function to print info

    return 0;
}

/* Notes: input and output details 
Code doesn't list the name of the people 
The ascending order only seems to work for only the weights of the users.
The weights' outputs don't include the names of the people.
i.e. Input: Please enter how many people:
2
Please enter the weights of people :
150
Please enter the weights of people :
115
Output of the weights sorted in ascending order: 
115
150
should have done outputs of the weights sorted in ascending order:
Mark - 150 Tina - 115
*/