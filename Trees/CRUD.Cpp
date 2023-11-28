#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* createNode(int data){
    Node* NN = new Node();
    NN->data = data;
    NN->left = NULL;
    NN->right = NULL;
    return NN;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        root = createNode(data);
    }
    else if(root->data >= data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << " ";
    }
}
void preorder(Node* root) {
    if (root != NULL) {
        std::cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
}

int main(){
    Node* root = NULL;

    int keys[] = {10, 4, 15, 2, 8, 12, 20};

    for(int keys: keys){
        root = insert(root, keys);
    }
    
    cout <<endl;
    cout << "Inorder: \n";
    inorder(root);
    cout <<endl;
    cout << endl;
    cout << "Preorder: \n";
    preorder(root);
    cout <<endl;
    cout << endl;
    cout << "Postorder: \n";
    postorder(root);
    cout << endl;
    cout << endl;
    return 0;
}




















































































// struct Node {
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* createNode(int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// Node* insert(Node* root, int data) {
//     if (root == NULL) {
//         root = createNode(data);
//     }
//     else if (data <= root->data) {
//         root->left = insert(root->left, data);
//     }
//     else {
//         root->right = insert(root->right, data);
//     }
//     return root;
// }

// bool search(Node* root, int data) {
//     if (root == NULL) {
//         return false;
//     }
//     else if (root->data == data) {
//         return true;
//     }
//     else if (data <= root->data) {
//         return search(root->left, data);
//     }
//     else {
//         return search(root->right, data);
//     }
// }

// int main() {
//     Node* root = NULL;
//     root = insert(root, 15);
//     root = insert(root, 10);
//     root = insert(root, 20);
//     root = insert(root, 25);
//     root = insert(root, 8);
//     root = insert(root, 12);

//     int number;
//     cout << "Enter number be searched\n";
//     cin >> number;
//     if (search(root, number) == true) {
//         cout << "Found\n";
//     }
//     else {
//         cout << "Not Found\n";
//     }
// }
