#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top;

void init(){
    top = NULL;
}

void push(int value){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;
    top = newNode;
}

void pop(){
    if(top == NULL){
        printf("\nUnderrflow\n");
    }
    else{
        struct Node *temp = top;
        printf("\nDeleted element: %d", temp->data);
        top = temp->next;
        free(temp);
    }
}

void display(){
    if(top == NULL){
        printf("\nStack is Empty\n");
    }
    else{
        struct Node *temp = top;
        while(temp->next != NULL){
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("%d-->NULL", temp->data);
    }
}