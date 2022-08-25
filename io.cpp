#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/* Read a sentence from the console.
Break the sentence into words using the space character as a delimiter.
Iterate over each word, if the word is a numeric value then print its value doubled,
-otherwise print out the word, with each output on its own line.
*/

int main(){
    string sentence;
    cout << "Please enter a sentence: ";
    getline(cin, sentence); //reads the sentence from console
    

    const char delim = ' ';
    
    return 0;
}