#include <iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

int main(){

// --- Create a small Linked List ---
    DoublyLinkedList List1(1);
    List1.append(2);
    List1.append(3);
    List1.append(4);
    List1.append(5);
    List1.append(6);
    List1.append(7);
    List1.append(8);
    List1.append(9);
    List1.append(10);
// ------------------------------------

// Testing

    List1.printList();

}