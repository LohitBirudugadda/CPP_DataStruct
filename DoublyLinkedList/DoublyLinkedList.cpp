#include <iostream>

using namespace std;

class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
    
        /*
        * Function: DoublyLinkedList
        * Description: Constructor that initializes a doubly linked list with a single node containing the given value.
        *              The new node becomes both the head and tail of the list.
        * Parameters:
        *    int value - The value to store in the initial node of the list.
        * Returns:
        *    None (constructor)
        */
        DoublyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        /*
        * Function: ~DoublyLinkedList
        * Description: Destructor that deallocates all nodes in the doubly linked list to free memory.
        * Parameters:
        *    None
        * Returns:
        *    None (destructor)
        */
        ~DoublyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    
        /*
        * Function: printList
        * Description: Prints all node values in the doubly linked list in order, separated by " <-> ".
        *              If the list is empty, prints "empty".
        * Parameters:
        *    None
        * Returns:
        *    void
        */
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty" << endl;
                return;
            }
            while (temp->next != nullptr) {
                cout << temp->value << " <-> ";
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    
        /*
        * Function: getHead
        * Description: Returns a pointer to the head node of the doubly linked list.
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
        * Description: Returns a pointer to the tail node of the doubly linked list.
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
        * Description: Returns the number of nodes in the doubly linked list.
        * Parameters:
        *    None
        * Returns:
        *    int - The length of the list.
        */
        int getLength() {
            return length;
        }

        /*
        * Function: append
        * Description: Adds a new node with the given value to the end of the doubly linked list.
        *              If the list is empty, the new node becomes both the head and tail.
        * Parameters:
        *    int value - The value to insert at the end of the list.
        * Returns:
        *    void
        */
        void append(int value){
            Node* newNode = new Node(value);
            
            if (length == 0){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        /*
        * Function: deleteLast
        * Description: Removes the last node from the doubly linked list.
        *              If the list has only one node, both head and tail are set to nullptr.
        *              Does nothing if the list is empty.
        * Parameters:
        *    None
        * Returns:
        *    void
        */
        void deleteLast(){
            if(length != 0){
                Node* temp = tail;
                
                if(length == 1){
                    head = nullptr;
                    tail = nullptr;
                }
                else{
                    tail = temp->prev;
                    tail->next = nullptr;
                }
                delete temp;
                length--;
            }
        }

        /*
        * Function: prepend
        * Description: Adds a new node with the given value to the beginning of the doubly linked list.
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
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        /*
        * Function: deleteFirst
        * Description: Removes the first node from the doubly linked list.
        *              If the list has only one node, both head and tail are set to nullptr.
        *              Does nothing if the list is empty.
        * Parameters:
        *    None
        * Returns:
        *    void
        */
        void deleteFirst(){
            if(length != 0){
                Node* temp = head;
                if(length == 1){
                    head = nullptr;
                    tail = nullptr;
                }
                else{
                    head = temp->next;
                    head->prev = nullptr;
                }
                delete temp;
                length--;
            }
        }

        /*
        * Function: get
        * Description: Returns a pointer to the node at the specified index in the doubly linked list.
        *              If the index is in the first half of the list, traversal starts from the head.
        *              If the index is in the second half, traversal starts from the tail for efficiency.
        *              Returns nullptr if the index is out of bounds.
        * Parameters:
        *    int index - The zero-based position of the node to retrieve.
        * Returns:
        *    Node* - Pointer to the node at the given index, or nullptr if the index is invalid.
        */
        Node* get(int index){
            if(index < 0 || index >= length){
                return nullptr;
            }
            Node* temp = head;
            if(index < (length / 2)){
                for(int i = 0; i < index; i++){
                    temp = temp->next;
                }
            }
            else if(index >= (length / 2)){
                temp = tail;
                for(int i = length - 1; i > index; i++){
                    temp = temp->prev;
                }
            }
            return temp;
        }

        /*
        * Function: set
        * Description: Updates the value of the node at the specified index in the doubly linked list.
        *              If the index is invalid, the function returns false.
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
            return 0;
        }

        /*
        * Function: insert
        * Description: Inserts a new node with the given value at the specified index in the doubly linked list.
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
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            length++;
            return 1;
        }

        /*
        * Function: deleteNode
        * Description: Deletes the node at the specified index in the doubly linked list.
        *              Handles deletion for the first node, last node, and middle nodes.
        * Parameters:
        *    int index - The zero-based position of the node to delete.
        * Returns:
        *    void
        */
        void deleteNode(int index){
            if(index < 0 || index > length){
                return;
            }
            else if(index == 0){
                this->deleteFirst();
                return;
            }
            else if(index == length-1){
                this->deleteLast();
                return;
            }
            Node* temp = this->get(index);
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            length--;
            return;
        }
};