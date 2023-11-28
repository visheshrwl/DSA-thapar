#include<iostream>
using namespace std;

//LL Creation
class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this-> next = NULL;
    }
};

//LL Insertion At Head

void insertAtHead(Node* &head, int d){
    //new Node Creation
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

//LL Insertion At Tail

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

//LL Traversal

void print(Node* &head){
    Node *temp = head;

    while(temp!= NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout <<endl;
}

int main(){

    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    print(head);
    insertAtTail(tail, 12);
    print(head);
    insertAtHead(head, 15);
    print(head);   
    return 0;
}