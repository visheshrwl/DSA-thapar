#include<iostream>
using namespace std;

class Node {
    public:
        char data;
        Node* next;
        Node* prev;
        Node(char data){
            this->data =data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    void insertionLast(char data){
        Node* newNode = new Node(data);
        if(!head){
            head = newNode;
            head->next = NULL;
            head->prev = NULL;
        }
        else {
            Node* current = head;
            while(current->next){
                current = current->next;
            }
            newNode->prev = current;
            newNode->next = NULL;
            current ->next = newNode;
        }
    }

    bool isPalindrome(){
        if(!head){
            return true;
        }

        Node* front = head;
        Node* rear = head;

        while(rear->next){
            rear = rear->next;
        }
        while (front!=rear && front->prev!=rear)
        {
            if(front->data != rear->data){
                return false;
            }
            front = front->next;
            rear = rear->prev;
        }
        return true;
    }
};

int main(){
    LinkedList d;
    d.insertionLast('n');
    d.insertionLast('a');
    d.insertionLast('m');
    d.insertionLast('a');
    d.insertionLast('n');

    if(d.isPalindrome()){
        cout << "the linkedlist is Palindrome.\n";
    }else{
        cout << "It is not Palindrome." <<endl;
    }

    return 0;
}