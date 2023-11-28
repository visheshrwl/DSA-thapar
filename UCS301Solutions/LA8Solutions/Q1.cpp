#include<iostream>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

TreeNode* insert(TreeNode* root, int data){
    if(root == NULL){
        return new TreeNode(data);
    }

    if(data < root->data){
        root->left = insert(root->left, data);
    } else{
        root->right = insert(root->right, data);
    }

    return root;
}

void preOrderTraversal(TreeNode* root){
    if(root== NULL){
        return;
    }
    else{
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    cout << endl;
}

void inOrderTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }else{
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
    cout << endl;
}

void postOrderTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }else{
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}


int main(){

    TreeNode* root = NULL;
    int datas[] = {1,2,3,4,5,6,7,8,9,10};

    for(int data: datas){
        root = insert(root, data);
    }

    cout << "PreOrder traversal: "<<endl;
    preOrderTraversal(root);
    cout << "InOrder traversal" << endl;
    inOrderTraversal(root);
    cout << "PostOrder Traversal" << endl;
    postOrderTraversal(root);

    return 0;
}