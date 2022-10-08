#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define MAXSIZE 20;

/*Calculate the results of Reverse Polish expressions that are provided by the useralculate the results of Reverse Polish 
expressions that are provided by the user.

Must use linked list to maintain the stack (array implementations won't work)

Must handle these errors 
1. Too many operators (+ - / *) 2. Too many operands (dbls) 3. Division by 0

- The program will take in a Polish expression that separates the operators and operands by a single space, and terminates
the expression with an equals sign.
- The program will continue to take and evaluate expressions until the user enters a zero (0) on a line by itself followed by a new line.
- Your sample output should show the handling of all the error conditions as well as make use of all of the operators.

Must include output at the end of the source code.
*/

struct Node{
    float num;
    struct Node *nextValue; 
};

//all of the functions under the stack class that will be implemented
//and written later on

class stack{
    public:
        Node *head;
    
    public:
        stack();
        void push(float value);
        float pop(); 
        float operands(); 
        float showStack();  
};

class reversePolish: public stack{
    public: //all of the math for the reverse polish notation
        void add();
        void subtract();
        void multiply();
        void divide();
};

stack::stack(){
    head = NULL;
}

void stack::push(float value){
    Node *temp = new Node;
    if (temp){
        temp->num = value;
        temp->nextValue = head; 
        head = temp;
    }
}

float stack::pop(){
    float count = 0;
    if (!head){
        return 0;
    }
    else{
        Node *temp = head;
        count = head->num;
        head = temp->nextValue; //points to next value
        delete(temp); //takes it off of the stack
    }
    return count;
}

float stack::operands(){ 
    int count = 0;
    for (Node *node = head; node; node = node->nextValue){
        count++;
    }
    return count;
}

float stack::showStack(){
    if (operands() != 1){ 
        cout << "Error: Too many operands or operators!" << endl; //catches the error
        return 1;
    }
    else{ //calculates if there are not too many operands or operators
        float temp = pop();
        cout << temp << endl;

        return temp; 
    }
    return 0;
}

//math functions to calculate user input for reverse polish not.

void reversePolish::subtract(){
    if (operands() >= 2){
        push(0 - pop() + pop());
    }
}
void reversePolish::multiply(){
    if (operands() >= 2){
        push(pop() * pop());
    }
}

void reversePolish::add(){
    if (operands() >= 2){
        push(pop() + pop());
    }
}

void reversePolish::divide(){
    float operand;
    operand = pop();

    if (operands() != 0){
        push(pop() / operand);
    }
    else{
        cout << "Error: Cannot divide by zero!" << endl; //error for division by 0
    }
}

//function prototypes - will be defined later when input is scanned in
int calculation(string & input, reversePolish & calc);
bool isOperator(string & input);

int main(){
    reversePolish calc;
    float num;
    string input; 
    cout << "Reverse Polish Notation : " << endl;
    cout << "Please enter your operators and operand :\nEnter E to exit\n";
    while (input != "E"){
        while(true){
            cin >> input; //scans user input
            if (input == "E"){ //breaks out of program
                break;
            }
            else if (istringstream(input) >> num){ //parses and checks if bigger than num
                calc.push(num); //if bigger then push the num
            }
            else if (isOperator(input)){ //use function prototypes above, function definitions below
                calculation(input, calc);
            }
        }
    }
}

bool isOperator(string & input){
    string operators = "-+*/"; //the four operators defined
    if (input.length() == 1){
        return operators.find_first_of(input[0] != string::npos); //compares until end of string
    }
    else{
        return false;
    }
}

int calculation(string & input, reversePolish & calc){
    switch(input[0]){ //switch to prompt program to call methods when operator and operands
    //are inputted by the user
        case '+': 
            calc.add();
            calc.showStack();
            break;
        case '-':
            calc.subtract();
            calc.showStack();
            break;
        case '*':
            calc.multiply();
            calc.showStack();
            break;
        case '/':
            calc.divide();
            calc.showStack();
            break;
        default: //if none of these operators then default break
            break;
    }
    return 0;
}

/* 
Sample Input and Output
Reverse Polish Notation :
Enter 0 to exit:
1
2
*
2 (answer)
1
-
1 (answer)
3
8
2
* 
Error: Too many operands or operators. 
2
0
/
Error: Cannot divide by zero!

*/


