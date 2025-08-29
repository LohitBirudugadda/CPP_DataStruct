#include <iostream>

using namespace std;

class Node {
    public:

        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class Queue {
    private:

        Node* first;
        Node* last;
        int length;

    public:

        /*
        * Function: Queue
        * Description: Constructor that initializes a queue with a single node containing the given value.
        *              The new node becomes both the first and last node of the queue, and the length is set to 1.
        * Parameters:
        *    int value - The value to store in the initial node of the queue.
        * Returns:
        *    None (constructor)
        */
        Queue(int value){
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

        /*
        * Function: ~Queue
        * Description: Destructor that deallocates all nodes in the queue to free memory.
        * Parameters:
        *    None
        * Returns:
        *    None (destructor)
        */
        ~Queue() {
            Node* temp = first;
            while (first) {
                first = first->next;
                delete temp;
                temp = first;
            }
        }

        /*
        * Function: printQueue
        * Description: Prints all values in the queue from the first to the last node.
        *              If the queue is empty, prints "Queue: empty".
        * Parameters:
        *    None
        * Returns:
        *    void
        */
        void printQueue() {
            if (length == 0) {
                cout << "Queue: empty" << endl;
                return;
            }
            Node* temp = first;
            cout << "Queue: ";
            while (temp) {
                cout << temp->value;
                temp = temp->next;
                if (temp) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }


        /*
        * Function: getFirst
        * Description: Returns a pointer to the first node of the queue.
        * Parameters:
        *    None
        * Returns:
        *    Node* - Pointer to the first node of the queue.
        */
        Node* getFirst() {
            return first;
        }

        /*
        * Function: getLast
        * Description: Returns a pointer to the last node of the queue.
        * Parameters:
        *    None
        * Returns:
        *    Node* - Pointer to the last node of the queue.
        */
        Node* getLast() {
            return last;
        }

        /*
        * Function: getLength
        * Description: Returns the number of nodes currently in the queue.
        * Parameters:
        *    None
        * Returns:
        *    int - The length (size) of the queue.
        */
        int getLength() {
            return length;
        }

        /*
        * Function: isEmpty
        * Description: Checks whether the queue is empty.
        * Parameters:
        *    None
        * Returns:
        *    bool - True if the queue has no nodes, false otherwise.
        */
        bool isEmpty() {
            if (length == 0) return true;
            return false;
        }

        /*
        * Function: enqueue
        * Description: Adds a new node with the given value to the end of the queue.
        *              If the queue is empty, the new node becomes both first and last.
        *              Otherwise, it is linked after the current last node.
        * Parameters:
        *    int value - The value to be stored in the new node.
        * Returns:
        *    void
        */
        void enqueue(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                first = newNode;
                last = newNode;
            }
            else{
                last->next = newNode;
                last = newNode;
            }
            length++;
        }

        /*
        * Function: dequeue
        * Description: Removes and returns the value from the front of the queue.
        *              If the queue is empty, returns INT_MIN.
        *              If there is only one node, both first and last are set to nullptr.
        *              Otherwise, the first pointer moves to the next node.
        * Parameters:
        *    None
        * Returns:
        *    int - The value of the node removed from the front.
        */
        int dequeue(){
            if(length == 0){
                return INT_MIN;
            }
            Node* temp = first;
            int dequeuedValue = first->value;
            if(length == 1){
                first = nullptr;
                last = nullptr;
            }
            else{
                first = first->next;
            }
            delete temp;
            length--;
            return dequeuedValue;
        }
};