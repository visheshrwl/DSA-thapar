#include<iostream>
using namespace std;

struct QNode {
    int data;
    QNode* next;
    QNode(int d){
        data = d;
        next = NULL;
    }
};

struct Queue{
    QNode *front, *rear;
    Queue(){front = rear = nullptr;}

    void enQueue(int x){
        QNode * temp = new QNode(x); // New LinkedList Node
        if(rear == NULL){
            front = rear = temp;
            return;
        }
        rear -> next = temp;
        rear = temp;
    }

    void deQueue(){
        if(front == NULL){
            return;
        }
        QNode* temp = front; //Store Previous Front
        front = front -> next; //Move Front one Node Ahead
        
        if(front == NULL) rear == NULL;
        delete(temp);
    }
};

int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.deQueue();

    
}