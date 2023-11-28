#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev =NULL;
    }
};

class DoublyLinkedList{
    public: 
        Node* head;
        DoublyLinkedList(){
            head = NULL;
        }
        void insertLast(int data){
            Node* newNode = new Node(data);
            if(!head){
                head = newNode;
                head->next = NULL;
                head->prev = NULL;
            }
            else{
                Node* current = head;
                while(current->next){
                    current = current->next;
                }
                newNode->prev = current;
                current->next = newNode;
                newNode->next = nullptr;
            }
        }
        int getSize(){
            int size = 0;
            Node* current = head;
            while(current){
                size++;
                current = current->next;
            }
            return size;
        }
};

class CircularLinkedList{
    public:
        Node* head;

        CircularLinkedList(){
            head = NULL;
        }
        void insertLast(int data){
            Node* newNode = new Node(data);
            if(!head){
                head = newNode;
                head->next = head;
                head->prev = head;
            }
            else{
                newNode->next = head;
                newNode->prev = head->prev;
                head->prev->next = newNode;
                head->prev = newNode;
            }
        }

        int getSize(){
            if(!head) return 0;
            int size = 0;
            Node*current = head;
            do{
                size++;
                current = current->next;
            }while(current != head);
            return size;
        }
};

int main(){
    DoublyLinkedList d;
    CircularLinkedList c;

    for(int i = 1; i<=5; i++){
        d.insertLast(i*10);
    }
    for(int i = 1; i<=6; i++){
        c.insertLast(i*10);
    }

    cout << "Size of doubly Linked List: "<< d.getSize() << endl;
    cout << "Size of Circular Linked List: "<< c.getSize() << endl;
}