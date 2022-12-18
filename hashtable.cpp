#include <iostream>
#include <sstream>
#include <string>
using namespace std;
/* 
Create a hash table class/struct.
Define an array that holds 27 elements.
Define a function called Hash(int)
-This function returns the modulo of that int by the size of the table (array).
Define an add function that takes an integer.
-This function takes the integer, determines the hash of that number by calling the above hash function, then adds it to the table using linear probing for collision resolution.
Define a function that looks up a value, it takes an integer, return -1 if the value is not in the table.
Create a main that allows the user to add and lookup items in the table.
*/
//Used Hashing.cpp by Professor for reference and help
const int SIZE = 27; //27 elements 
const int EMPTY = -1;
#define DISPLAY true

class HashTable{
    int table[SIZE]; // where our data will be held
    bool probe(int data){ // linear probing function
        int index = data % SIZE;
        int probeFcn = (index + 1) % SIZE; // start of the linear probing
        while (index != probeFcn){
        #ifdef DISPLAY 
            cout << "Probing at " << probeFcn << ". ";
        #endif
        if (table[probeFcn] == EMPTY){
        #ifdef DISPLAY 
            cout << "Inserted.\n";
        #endif
        table[probeFcn] = data;
        return true;
        }
        probeFcn = ++probeFcn % SIZE; // continues linear probing
        }
        #ifdef DISPLAY 
            cout << "==== TABLE FULL ====\n";
        #endif
        return false; //returns false since the table is full
    }
public:
    HashTable(){
    #ifdef DISPLAY 
        cout << "Building hash table.\n";
    #endif
    for (int i = 0; i < SIZE; i++){
        table[i] = EMPTY;
    }
    }
    bool insert(int data){
        #ifdef DISPLAY 
            cout << "Inserting " << data << " at ";
        #endif
        if (table[data % SIZE] == EMPTY){
        #ifdef DISPLAY 
            cout << "at " << data % SIZE << endl;
        #endif
        table[data % SIZE] = data;
        return true;
        }
        else{
            return probe(data);
        }
    }
};

int main (){
    HashTable *data = new HashTable();
    data->insert(100);
    data->insert(99);
    data->insert(9);
    data->insert(41);
    data->insert(32);
    data->insert(12);
    data->insert(6);
    data->insert(11);
    data->insert(18);
    data->insert(88);
    data->insert(75);
    data->insert(33);
    data->insert(21);
    data->insert(67);
    data->insert(66);
    data->insert(43);
    data->insert(45);
    data->insert(65);
    data->insert(17);
    data->insert(1);
    data->insert(13);
    return 0;
}