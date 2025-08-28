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

class SinglyLinkedList {
    private:

        Node* head;
        Node* tail;
        int length;

    public:

        /*
        * Function: SinglyLinkedList
        * Description: Constructor that initializes a singly linked list with a single node containing the given value.
        * Parameters:
        *    int value - The value to store in the initial node of the list.
        * Returns:
        *    None (constructor)
        */
        SinglyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        /*
        * Function: ~SinglyLinkedList
        * Description: Destructor that deallocates all nodes in the singly linked list to free memory.
        * Parameters:
        *    None
        * Returns:
        *    None (destructor)
        */
        ~SinglyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        /*
        * Function: printList
        * Description: Prints all node values in the singly linked list in order, separated by " -> ".
        *              If the list is empty, prints "empty".
        * Parameters:
        *    None
        * Returns:
        *    void
        */
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        /*
        * Function: getHead
        * Description: Returns a pointer to the head node of the singly linked list.
        * Parameters:
        *    None
        * Returns:
        *    Node* - Pointer to the head node of the list.
        */
        Node* getHead() {
            return head;
        }

        /*
        * Function: getTail
        * Description: Returns a pointer to the tail node of the singly linked list.
        * Parameters:
        *    None
        * Returns:
        *    Node* - Pointer to the tail node of the list.
        */
        Node* getTail() {
            return tail; 
        }

        /*
        * Function: getLength
        * Description: Returns the number of nodes in the singly linked list.
        * Parameters:
        *    None
        * Returns:
        *    int - The length of the list.
        */
        int getLength() {
            return length;
        }

        /*
        * Function: makeEmpty
        * Description: Deletes all nodes in the singly linked list, deallocating memory and resetting the list to an empty state.
        * Parameters:
        *    None
        * Returns:
        *    void
        */
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
            length = 0;
        }

        /*
        * Function: append
        * Description: Adds a new node with the given value to the end of the singly linked list.
        *              If the list is empty, the new node becomes both the head and tail.
        * Parameters:
        *    int value - The value to insert at the end of the list.
        * Returns:
        *    void
        */
        void append(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
                length += 1;
            }
            
            else{
                tail->next = newNode;
                tail = newNode;
                length += 1;
                
            }
        }

        /*
        * Function: deleteLast
        * Description: Removes the last node from the singly linked list.
        *              If the list is empty, the function does nothing.
        *              If the list has only one node, both head and tail are set to nullptr.
        * Parameters:
        *    None
        * Returns:
        *    void
        */
        void deleteLast(){
            if(length == 0){
                return;
            }
            Node* temp = head;
            
            if(length == 1){
                head = nullptr;
                tail = nullptr;
            }
            else{
                Node* pre = head;
                while(temp->next != nullptr){
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
            }
            delete temp;
            length -= 1;
        }

        /*
        * Function: prepend
        * Description: Adds a new node with the given value to the beginning of the singly linked list.
        *              If the list is empty, the new node becomes both the head and tail.
        * Parameters:
        *    int value - The value to insert at the beginning of the list.
        * Returns:
        *    void
        */
        void prepend(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
            length += 1;
        }
        
        /*
        * Function: deleteFirst
        * Description: Removes the first node from the singly linked list.
        *              If the list is empty, the function does nothing.
        *              If the list has only one node, both head and tail are set to nullptr.
        * Parameters:
        *    None
        * Returns:
        *    void
        */
        void deleteFirst(){
            if (length == 0){
                return;
            }
            Node* temp = head;
            if(length == 1){
                head = nullptr;
                tail = nullptr;
                length--;
            }
            else{
                head = head->next;
                delete temp;
                length--;
            }
        }

        /*
        * Function: get
        * Description: Returns a pointer to the node at the specified index in the singly linked list.
        *              If the index is out of bounds, returns nullptr.
        * Parameters:
        *    int index - The zero-based position of the node to retrieve.
        * Returns:
        *    Node* - Pointer to the node at the given index, or nullptr if index is invalid.
        */
        Node* get(int index){
            if(index < 0 || index >= length){
                return nullptr;
            }
            Node* temp = head;
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }
            
            return temp;
        }

        /*
        * Function: set
        * Description: Updates the value of the node at the specified index in the singly linked list.
        *              If the index is invalid, the function does nothing and returns false.
        * Parameters:
        *    int index - The zero-based position of the node to update.
        *    int value - The new value to assign to the node.
        * Returns:
        *    bool - True if the node was successfully updated, false if the index is out of bounds.
        */
        bool set(int index, int value){
            Node* temp = this->get(index);
            if(temp != nullptr){
                temp->value = value;
                return 1;
            }
            else{
                return 0;
            }
        }

        /*
        * Function: insert
        * Description: Inserts a new node with the given value at the specified index in the singly linked list.
        *              If the index is 0, the node is prepended. If the index equals the list length, the node is appended.
        *              Returns false if the index is out of bounds.
        * Parameters:
        *    int index - The zero-based position where the new node should be inserted.
        *    int value - The value to store in the new node.
        * Returns:
        *    bool - True if the insertion was successful, false if the index is invalid.
        */
        bool insert(int index, int value){
            if(index < 0 || index > length){
                return 0;
            }
            else if(index == 0){
                this->prepend(value);
                return 1;
            }
            else if(index == length){
                this->append(value);
                return 1;
            }
            Node* newNode = new Node(value);
            Node* temp = this->get(index-1);
            newNode->next = temp->next->next;
            temp->next = newNode;
            length++;
            return 1;
        }

        /*
        * Function: deleteNode
        * Description: Deletes the node at the specified index in the singly linked list.
        *              If the index is 0, deletes the first node.
        *              If the index is the last node, deletes the last node.
        *              Does nothing if the index is out of bounds.
        * Parameters:
        *    int index - The zero-based position of the node to delete.
        * Returns:
        *    void
        */
        void deleteNode(int index){
            if(index < 0 || index >= length){
                return;
            }
            
            if(index == 0){
                this->deleteFirst();
                return;
            }
            if(index == length - 1){
                this->deleteLast();
                return;
            }
            Node* prev = this->get(index - 1);
            Node* temp = prev->next;
            prev->next = temp->next;
            delete temp;
            length--;
        }

        /*
        * Function: reverse
        * Description: Reverses the singly linked list in place.
        *              After reversal, the head becomes the tail and the tail becomes the head.
        * Parameters:
        *    None
        * Returns:
        *    void
        */
        void reverse(){
            Node* temp = head;
            head = tail;
            tail = temp;
            Node* after = nullptr;
            Node* before = nullptr;
            for(int i = 0; i < length; i++){
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }
        }
};