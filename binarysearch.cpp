#include <iostream>
#include <cstdlib>
using namespace std;
/*
Create a node class/struct
-Data field
-2 self referential pointers

Create a BST class/struct
-Node field
Methods:
Add (data)
-Adds the data to the tree in sorted order.
Print()
-Prints all the nodes using inorder traversal
*/

struct Node{
    int data;
    Node *left, *right;

    Node(){
        left = right = 0; //set all of it to 0
    }

    Node (int data, Node *leftside = 0, Node *rightside = 0){
        this->data = data;
        left = leftside;
        right = rightside;
    }
};

class BSearchTree{
    public:
        Node *origin;

        BSearchTree(){
            origin = 0; //set the origin = 0
        }

        //will add the data to the tree in a sorted order
        bool add(int data){
            Node *newNode = new Node(data);
            if (origin == 0){
                origin = newNode;
                return true; //is empty = true
            }
            Node *temp = origin; //set the temp to the origin
            while (true){//only if it satisfies the if condition 
                if (data < temp->data){ //left traversal
                    if (temp->left == 0){ //if there's a pos
                        temp->left = newNode; 
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else if (data > temp->data){ //right traversal
                    if (temp->right == 0){
                        temp->right = newNode;
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
                else if (data == temp->data){ //checks for repeats
                    return false;
                }
            }
        }

        //will print all the nodes inorder of the traversals for user in the terminal
        void print(Node *d){
            if (d != NULL){
                print(d->left);  //prints left traversal
                cout << d->data << " ";
                print(d->right); //prints right traversal
            }
        }
};

int main(){
    BSearchTree b;
    b.add(3);
    b.add(1);
    b.add(2);
    b.add(4);
    //should output in order 1 2 3 4
    b.print(b.origin);
}