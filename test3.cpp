#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
class BinaryNode{
    public:
        int value;
        BinaryNode* left, * right;
        BinaryNod(){
            value = 0;
            left = right = 0;
        }
};

class Bst{
    private:
        BinaryNode* root;
        void Traverse(BinaryNode* sub);
    public: 
        void Traverse();
};

void Traverse(BinaryNode* sub){
    struct BinaryNode *temp = (struct BinaryNode *)malloc(sizeof(struct BinaryNode));
    temp->value = sub;
    temp->left = temp->right = NULL;
    return temp;
}

void Traverse(){
    if (root == NULL){
        return;
    }
    else{
    Traverse(root->left);
    Traverse(root->right);
    cout << root->value;
    }
}
*/

class BinaryNode{
    public:
        int value;
        BinaryNode *left, *right;
        BinaryNode(){
            value = 0;
            left = right = 0;
        }
};

class BinaryTree{
    private:
        BinaryNode *root;
        int FindLeftMostLeaf(BinaryNode *root);
    public:
        int FindLeftMostLeaf();
};

int FindLeftMostLeaf(BinaryNode *root){
    if (root == NULL){
        return;
    }
    queue<BinaryNode*> l;
    l.push(root);

    while (l.empty == false){
        int num = l.size();
        for (int i = 0; i < num; i++){
            BinaryNode * temp = l.front();
            l.pop();
            if (i == 0){
                cout << temp->value;
            }
            if (i == num -1){
                cout << temp->value;
            }
            if (temp->left){
                l.push(temp->left);
            }
        }
    }
}