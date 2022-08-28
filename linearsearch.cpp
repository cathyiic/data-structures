#include <iostream>
using namespace std;
/* Search an un-ordered array an integers for a value, if the 
value is found return the index of its position in the array, 
if not found, return -1.
*/

int linearSearch(int arr1[], int index, int x){
    for (int i = 0; i < index; i++){
        if (arr1[i] == x){
            return i;
        }
        //return -1;
        }
    return -1;
}

int main(){
    int arr1[] = {1, 2, 3, 4};
    int index = sizeof(arr1) / sizeof(arr1[0]);
    int x = 4;  //fields to check function linear search

    int search = linearSearch(arr1, index, x); //call the function
    if (search == -1){ 
        cout << "That value is not in the array.\n";
    }
    else{
        cout << "The value is in the array at index of " << search << "\n";
    }

    return 0;
}