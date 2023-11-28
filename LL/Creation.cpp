#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    //Constructor
    Node(int data){
        this-> data = data;
        this -> next = NULL;
    }
};

void InsertAtHead(Node* &head, int d){
    //New Node Create

    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

// void insertAtPosition(Node* &head, int position, int d){

//     //insert at start
//     if(position == 1){
//         InsertAtHead(head, d);
//         return;
//     }    


//     //insert at end
//     if(len == position -1){
//         InsertAtTail(head, d);
//     }

//     Node* temp = head;
//     int count = 1;

//     while(count < position -1){
//         temp = temp -> next;
//         count++;
//     }

//     //Creating a new node

//     Node* nodeToInsert = new Node(d);

//     nodeToInsert ->next = temp -> next;
//     temp -> next = nodeToInsert;
// }

void print(Node* &head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    //Created a new Node
    Node* node1 = new Node(10);
    // cout << node1 -> data <<endl;
    // cout << node1 -> next <<endl;

    //Head pointed to Node1
    Node* head = node1;
    Node* tail = node1;

    InsertAtTail(tail, 12);
    InsertAtTail(tail, 15);
    print(head);

    // insertAtPosition(head, 4, 22);
    InsertAtTail(tail, 15);
    print(head);

    return 0;
}