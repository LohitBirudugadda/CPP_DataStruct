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

        SinglyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~SinglyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

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

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }

        int getLength() {
            return length;
        }

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