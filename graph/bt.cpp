#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree(Node* root){
    cout << "Enter data: "<<endl;
    int d;
    cin >> d;

    root = new Node(d);

    if(d==-1){
        return NULL;
    }
    cout << "Enter data for inserting in left of "<<d<<endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of "<<d<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout <<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
        }
    }
}