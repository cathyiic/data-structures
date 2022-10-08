#include <iostream>
using namespace std;
#define MAXSIZE 20

/*
Create a binary tree class: 
- Data array field (private)
- Count field

Add Function(data):
- The add method takes a data point, add it to the count position in the array then increases the count.
- Print Function 

Preorder(int):
- Recursive method that prints all the nodes in a VLR pattern.
(Remember 2i + 1 & 2i + 2)
*/

struct TNode{
    int data;
    struct TNode *left;
    struct TNode *right;
    TNode(int data){
        this->data = data;
        left = right = NULL;
    }
};

class BTree{
    private:
        int size, count;
    public:
        int arr1[MAXSIZE];
        void add(int data){
            if(count >= size){
                return;
            }
            else{
                arr1[count++] = data;
            }
        }
        void preorder(struct TNode *temp){
            if (temp != NULL){
                cout << temp->data << " ";
                preorder(temp->left);
                preorder(temp->right);
            }
        }
        void printInf(){
            for (int i = 0; i < count; i++){
                cout << arr1[i] << " " << endl; 
            }
        }
};

/*
For testing
int main(){
    BTree *b;
    for (int i = 0; i < 21; i++){
        b->add(i);
    }
    TNode *root = new TNode(1);
    root->left = new TNode(2);
    root->right = new TNode(3);
    
    root->left->left = new TNode(4);
    root->left->right = new TNode(5);
    root->right->left = new TNode(6);
    root->right->right = new TNode(7);

    cout << "Here is the preorder: ", b->preorder(root);
    b->printInf();
    return 0;
}
*/
