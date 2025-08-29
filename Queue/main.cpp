#include <iostream>
#include "Queue.cpp"

using namespace std;

int main(){

/*
* Queues are FIFO (First In First Out)
*/

// --- Create a small Queue ---
    Queue Queue1(1);
    Queue1.enqueue(2);
    Queue1.enqueue(3);
    Queue1.enqueue(4);
    Queue1.enqueue(5);
    Queue1.enqueue(6);
    Queue1.enqueue(7);
    Queue1.enqueue(8);
    Queue1.enqueue(9);
    Queue1.enqueue(10);
// ------------------------------------

// Testing

    Queue1.dequeue();

    Queue1.printQueue();

}