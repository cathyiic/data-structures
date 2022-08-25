#include <iostream>
using namespace std;

/* Program logic:
Ask the user for how big to size the array.
Create an array based upon that size.
Ask for a number, add that number to the array.
Repeat adding to the end until all numbers have been entered 
or until they enter -1 for the number.
Print the list.
Note, the new keyword is expected.
*/

int main(){
    int size;
    cout << "Please enter how big to size the array: ";
    cin >> size;
    int *arr1 = new int(size); //new keyword used here

    int num1;
    cout << "Please enter a number: " << endl;
    for (int i = 0; i < size; i++){ //loops user nums to fill array size
        cin >> num1;
        if (num1 == -1){
            size = i;
            break; //entering -1 stops program
        }
        arr1[i] = num1;
    }

    for (int i = 0; i < size; i++){ //print the array
        cout << arr1[i];
    }
    cout << endl;


    return 0;
}