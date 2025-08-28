#include <iostream>
#include "Stack.cpp"

using namespace std;

int main(){

/*
* Stacks are LIFO (Last In First Out)
*/

// --- Create a small Stack ---
    Stack Stack1(1);
    Stack1.push(2);
    Stack1.push(3);
    Stack1.push(4);
    Stack1.push(5);
    Stack1.push(6);
    Stack1.push(7);
    Stack1.push(8);
    Stack1.push(9);
    Stack1.push(10);
// ------------------------------------

// Testing


    Stack1.printStack();

}