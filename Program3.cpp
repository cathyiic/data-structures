#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
Build a binary search tree, using links (not an array) for 15 records. 
The data in these records will hold names and their associated weights. Read the data from the screen.

Required functionality (Each # should be separate methods):
-Build the tree from the unique set of names (names are the key value) and their associated weights.
-Execute a preorder traversal
-Execute an inorder traversal
-Execute a postorder traversal
-Find and print the height of the tree using recursion, do not add a height variable to the tree structure,
the algorithm stack should hold this.
-Determine the number of leaves and print the result (remember a leaf has no children).
-Implement search functionality that will search for a name and indicate the weight for that individual if they exist in the structure, otherwise stating no match exists.
-Determine the lowest weight contained in the tree.
-Find the first name in alphabetical order (this should not go through every node, unless the tree happens to be a linked list).

Submit  the following items:
Source code.
Sample output.
Copy the output and place this as a comment at the bottom of your source code.
*/
//Referenced to geeksforgeeks on calculting depth of a BST : https://www.geeksforgeeks.org/find-the-maximum-depth-or-height-of-a-tree/

struct Node{
    string name;
    float weight;
    Node* left;
    Node* right;
};

Node* node(string name, float weight){
    Node* newNode = new Node();
    newNode->name = name;
    newNode->weight = weight;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//preorder traversal
void preorder(Node *root){
    if (root != NULL){
        cout << root->name << "(" << root->weight <<") " << endl; //prints before
        preorder(root->left);
        preorder(root->right);
    }
}
//inorder traversal 
void inorder(Node *root){
    if (root != NULL){
        inorder(root->left);
        cout << root->name << "(" << root->weight <<") " << endl; //prints in between
        inorder(root->right);
    }
}

//postorder traversal
void postorder(Node *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->name << "(" << root->weight <<") " << endl; //prints after
    }

}

//print binary search tree 
void print (Node *ptr, float level){
    if (ptr != NULL){
        print(ptr->right, level + 1); 
        //goes from the left of the tree to the right and prints
        for (int i = 0; i < level; i++){
            cout << " " << endl;
        }
        cout << ptr->name << "("<<ptr->weight<<")" << endl;
        print(ptr->left, level + 1);
    }
}

//compare the heights
int max(int leftside, int rightside){
    if(leftside >= rightside){
        return leftside;
    }
    else{
        return rightside;
    }
}

//calculate the height by finding the maxdepth
//the maxdepth is the number of nodes along longest path down to the farthest left node
int calculateHeight(Node* node){
    if (node == NULL){
        return 0;
    }
    else{
        int leftside = calculateHeight(node->left);
        int rightside = calculateHeight(node->right);

        if (leftside > rightside){
            return leftside + 1;
        }
        else{
            return rightside + 1;
        }
    }
}

//calculate the number of leaves in the binary tree
unsigned int calculateLeaves(Node* node){
    if (node == NULL){
        cout << "0 leaves.\n" << endl;
    }
    if (node->left == NULL && node->right == NULL){
        cout << "0 leaves.\n" << endl;
    }
    else{
        int total = calculateLeaves(node->left) + calculateHeight(node->right);
        cout << total + " leaves.\n" << endl;
    }
    return 0;
}

//determine the lowest weight in the tree
int lowestWeight(Node* node){
    Node* temp = node;
    while (temp->left != NULL){
        temp = temp->left;
    }
    return temp->weight;
}

//find first name in alphabethical order
Node* alphabet(Node *root, string name, float weight){
    //if the root empty then will add a root
    if (root == NULL){
        root = node(name, weight);
    }
    //if root exists, compare
    else if (name <= root->name){
        root->left = alphabet(root->left, name, weight);
    }
    //if the new name is after our root
    else if (name > root->name){
        root->right = alphabet(root->right, name, weight);
    }
    return root;
}

int main(){
    Node* root = NULL;
    string name;
    float weight;
    int count = 0;
    int userin;
    cout << "Please enter how many people you would like to record" << endl;
    cin >> userin;
    while (count < userin){
        cout << "Please enter the name of the person.\n";
        cin >> name;
        cout << "Please enter the weight of that person.\n";
        cin >> weight;
        count++;
    }
    cout << "Here is the first name in alphabethical order : " << endl;
    alphabet(root, name, weight);

    cout << "Here is the preorder : " << endl;
    preorder(root);

    cout << "Here is the inorder : " << endl;
    inorder(root);
    
    cout << "Here is the postorder : " << endl;
    postorder(root);

    cout << "Here is the lowest weight in the tree : " << endl;
    lowestWeight(root);

    cout << "Here is the number of leaves in the tree : " << endl;
    calculateLeaves(root);

    cout << "Here is the height of the tree : " << endl;
    int max();
    calculateHeight(root);

    return 0;
}

//output
/*
Please enter how many people you would like to record
2
Please enter the name of the person.
cathy
Please enter the weight of that person.
110
Please enter the name of the person.
hao  
Please enter the weight of that person.
160
Here is the first name in alphabethical order : cathy
Here is the preorder : 
Here is the inorder : 
Here is the postorder : 
Here is the lowest weight in the tree : 110
*/

//NOTE: for some reason, my program does not seem to print out the preorder, inorder, or the postorder
//even though I called the functions