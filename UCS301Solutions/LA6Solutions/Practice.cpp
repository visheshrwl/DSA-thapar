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
        this->prev = NULL;
    }
};

class doublyLinkedList{
    public:
        Node* head;
        doublyLinkedList(){
            head = NULL;
        }

        void insertionLast(int data){
            Node* newNode = new Node(data);
            if(!head){
                head = newNode;
                head->next = NULL;
                head->prev = NULL;
            }
            else{
                Node* current = head;
                while(current -> next){
                    current = current->next;
                }
                newNode->prev = current;
                current ->next = newNode;
                newNode->next = NULL;
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

class circularLinkedlist{
    public:
        Node* head;

        circularLinkedlist(){
            head = NULL;
        }

        void insertionAtLast(int data){
            Node* newNode = new Node(data);
            if(!head){
                head = newNode;
                head->next = head;
                head->prev= head;
            }
            else{
                newNode->next = head;
                newNode->prev = head->prev;
                head->prev->next = newNode;
                head ->prev = newNode;
            }
        }

        int getSize(){
            if(!head) return 0;
            int size = 0;
            Node* current = head;
            while(current->next!= head){
                size++;
                current = current->next;
            }
            return size+1;
        }

        //OT, Software Engineering,DBMS, DAA, AI; 
};

int main(){
doublyLinkedList d;
circularLinkedlist c;
for (int i = 0; i < 10; i++)
{
d.insertionLast(i*10);
}
for (int i = 0; i < 10; i++)
{
    c.insertionAtLast(i*10);
}
cout << "Size of doubly linkedlist is: "<< d.getSize()<<endl;
cout << "Size of circular linkedlist is: "<< c.getSize()<<endl;
}