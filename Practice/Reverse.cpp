#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this-> data = data;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
        while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<endl;
}

void insertionAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void reverse(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    reverse(head, forward, curr);
    curr->next = prev;
}

Node* reverseFun(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return head;
}

int main(){
    Node * head = new Node(9);
    insertionAtHead(head, 7);
    insertionAtHead(head, 5);
    insertionAtHead(head, 3);
    print(head);

    reverseFun(head);
    print(head);

    return 0;
}