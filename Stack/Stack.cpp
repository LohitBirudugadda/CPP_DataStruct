#include <iostream>
#include <climits>

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

class Stack {
    private:

        Node* top;
        int height;
        
    public:

        /*
        * Function: Stack
        * Description: Constructor that initializes a stack with a single node containing the given value.
        *              The new node becomes the top of the stack, and the height is set to 1.
        * Parameters:
        *    int value - The value to store in the initial node of the stack.
        * Returns:
        *    None (constructor)
        */
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }
    
        /*
        * Function: ~Stack
        * Description: Destructor that deallocates all nodes in the stack to free memory.
        * Parameters:
        *    None
        * Returns:
        *    None (destructor)
        */
        ~Stack() {
            Node* temp = top;
            while (top) {
                top = top->next;
                delete temp;
                temp = top;
            }
        }
    
        /*
        * Function: printStack
        * Description: Prints all values in the stack from top to bottom.
        * Parameters:
        *    None
        * Returns:
        *    void
        */
        void printStack() {
            Node* temp = top;
            while (temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
    
        /*
        * Function: getTop
        * Description: Returns a pointer to the top node of the stack.
        * Parameters:
        *    None
        * Returns:
        *    Node* - Pointer to the top node of the stack.
        */
        Node* getTop() {
            return top;
        }

        /*
        * Function: topValue
        * Description: Returns the value stored in the top node of the stack.
        *              If the stack is empty, returns INT_MIN as an error indicator.
        * Parameters:
        *    None
        * Returns:
        *    int - The value of the top node, or INT_MIN if the stack is empty.
        */
        int topValue() {
            if (top) return top->value;
            return INT_MIN;
        }
    
        /*
        * Function: getHeight
        * Description: Returns the number of nodes currently in the stack.
        * Parameters:
        *    None
        * Returns:
        *    int - The height (size) of the stack.
        */
        int getHeight() {
            return height;
        }
        
        /*
        * Function: makeEmpty
        * Description: Deletes all nodes in the stack, deallocating memory and resetting the stack to an empty state.
        * Parameters:
        *    None
        * Returns:
        *    void
        */
        void makeEmpty() {
            Node* temp;
            while (top) {
                temp = top;
                top = top->next;
                delete temp;
            }
            height = 0;
        }
        
        /*
        * Function: push
        * Description: Adds a new node with the given value to the top of the stack.
        * Parameters:
        *    int value - The value to push onto the stack.
        * Returns:
        *    void
        */
        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        /*
        * Function: pop
        * Description: Removes the top node from the stack and returns its value.
        *              If the stack is empty, returns INT_MIN as an error indicator.
        * Parameters:
        *    None
        * Returns:
        *    int - The value of the popped node, or INT_MIN if the stack is empty.
        */
        int pop(){
            if(height == 0){
                return INT_MIN;
            }
            
            Node* temp = top;
            int poppedValue = top->value;
            top = temp->next;
            delete temp;
            height--;
            
            return poppedValue;
        }
};