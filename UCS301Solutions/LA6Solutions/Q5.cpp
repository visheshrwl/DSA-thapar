#include<iostream>
using namespace std;

class Node{
    public:
        int data; 
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

bool iscircular(Node* &head){
    Node* temp = head;
    if(!temp){
        return false;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        if(slow ==fast){
            return true;
        }

        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main(){
    Node* head = new Node(5);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head->next->next->next->next = head;

    if(iscircular(head)){
        cout << "the linkedlist is Circular"<<endl;
    }else{
        cout << "the linkedlist is not Circular"<<endl;
    }
    return 0;
}