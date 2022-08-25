#include <iostream>

using namespace std;


int main(){
    int x = 5;
    int *y = &x;
    int *p = new int();

    cout << "Our int: " << x << endl;
    cout << "Our local pointer: " << y << endl;
    cout << "Our heap pointer: " << p << endl;

    cout << "Dereferencing y: " << *y << " and p is whatever" << *p << endl;

    cout << "Local var x " << &x << endl;
    cout << "Local var y " << &y << endl;
    cout << "Local var p " << &p << endl;

    function();


    

}