#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node (int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

void InsertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void display(Node* &head){
    Node* temp = head;

    while(!temp){
        cout << temp->data<< " ";
        temp = temp->next;
    }
}

int main(){
    Node* head = new Node(20);
    // InsertAtTail(head, 100);
    // InsertAtTail(head, 40);
    // InsertAtTail(head, 80);
    // InsertAtTail(head, 60);
    display(head);
}