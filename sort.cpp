#include <iostream>
using namespace std;
#define MAXSIZE 20
/* 
Write a sort function that takes an array and sorts the values.
*/
// I will be using a bubble sort algorithm for my function

void sort(int arr[], int a){
    for (int i = 0; i < a - 1; i++){
        for (int j = 0; j < a - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]); //condition that sorts them
            }
        }
    }
}

//you can define the values in int main() or use a scanner to get 
//the user's choice for the values. 
//but since the question just asks to write a sort function,
//i only wrote the sort function



