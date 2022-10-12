#include <iostream>
using namespace std;
#include <string>

//Credits to Professor Glenn Cuevas CCC TechConnect Video walking through 
//the graph matrix lab. Used his video for most of the code.

/*
Create a matrix based graph representation.
It will need to support the following operations.
Ask the user how many points there are.
Ask the user to label those points, ie "A", "B", "C"...
Define the matrix as a square matrix based on the number of points, also keep an array of the labels.
Repeatedly ask the user to define edges between two points. Add these edges to the matrix.
Have a list method that will list out all of the edges in the graph.
*/

class Node{
    public:
    int weight;
    char label;
    Node *next;
};

class List{
    List *head;
    char* labels;
    int weight;
    char label;
    public:
    void Add(char label, int weight){
        if (head == 0){
            //head = new Node();
            head->weight = weight;
            head->label = label;
        }
        else{
            //sorted insert
            if (label < head->label)
            //insert front 
            ;
            else
            ; //loop to insert point   
        }

    }
    int Insert(char fromLabel, char tlabel, int weight){ 
    }
};

class Matrix{
    private:
    char* vertexLabels;
    int **matrix;
    int size;

    public: 
    Matrix(int size){
        this->size = size;
        matrix = new int*[size];
        for (int i = 0; i < size; i++){
            matrix[i] = new int[size];
        }
    }

    void Print(){
        cout << "Matrix\n";
        for (int row = 0; row < size; row++){
            //inner loop prints a row
            for (int col = 0; col < size; col++){
                cout << matrix[row][col] << " ";
            }
            cout << endl;
        }
    }
    int IndexOfVertex(char vertexLabel){
        int index = -1;
        for (int i = 0; i < size; i++){
            if (vertexLabels[i] == vertexLabel){
                return i;
            }
            return index;
            }
        }
    void Add(char row, char col){
        int rowIndex = IndexOfVertex(row);
        int colIndex = IndexOfVertex(col);
        if (rowIndex == -1 || colIndex == -1){
            cout << "Invalid index found.\n";
            throw;
        }
        matrix[rowIndex][colIndex] = 1;
        matrix[colIndex][rowIndex] = 1; // make this a simple graph
    }
};

int main(){
    int numV;
    char labelName;
    Matrix *m = new Matrix(10);
    m->Print();
    //loop asking for a pair of verticies, ie A B
    m->Add('A', 'B');
    m->Add('B', 'A');
    m->Print();
    cout << "How many vertices? \n" << endl;
    cin >> numV;
    while (numV){
        cout << "What is the label for that vertex? \n" << endl;
        cin >> labelName;
    }
    return 0;
}