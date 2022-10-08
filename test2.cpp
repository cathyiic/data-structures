#include <iostream>
using namespace std;


//implement AddToHead(int data
/*
class Link{
    public:
    int info;
    Link* prev;
    Link* next;
};

class List{
    Link* head;
    Link* tail;
   void addAtHead(int data){
    if (head == NULL){
        head = new List(data);
        head->prev = NULL;
    }
    else{
        Link *temp = new Link(data);
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;
    }
}
};

*/
int Function(int p){
    if (p == 0){
        cout << "0\n";
    }
    else{
        cout << Function(p/2) << endl;
    }
    return p;
}
