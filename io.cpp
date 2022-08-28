#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
using namespace std;
/* Read a sentence from the console.
Break the sentence into words using the space character as a delimiter.
Iterate over each word, if the word is a numeric value then print its value doubled,
-otherwise print out the word, with each output on its own line.
*/

int main(){
    string storage;
    string sentence;
    int index;
    float num;
    cout << "Please enter a sentence: ";
    getline(cin, sentence); //reads the sentence from console

    //const char delim = ' ';
    stringstream mystr(sentence); //string stream, suggested by prof in discord
    vector<string> words;

    while (mystr >> storage){
        words.push_back(storage);
    }

    for (int i = 0; i < words.size(); i++){
        if (sentence[i] == isdigit(num)){
            return i * 2;
        }
        cout << words[i] << endl;
    }
    
    return 0;
}