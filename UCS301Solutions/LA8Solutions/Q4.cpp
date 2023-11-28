#include<bits/stdc++.h>
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

class BinaryTree{
    public: 
    TreeNode* root;

    BinaryTree(){
        root = NULL;
    }

    bool isBST(){
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

    private:
        bool isBSTUtil(TreeNode* node, int minValue, int maxValue){
            if(node == NULL){
                return true;
            }

            if(node->data <= minValue || node->data >= maxValue){
                return false;
            } 

            return isBSTUtil(node->left, minValue, node->data) && isBSTUtil(node->right, node->data, maxValue);
        }
};

int main(){
 BinaryTree binaryTree;

    // Construct a sample binary tree
    binaryTree.root = new TreeNode(10);
    binaryTree.root->left = new TreeNode(5);
    binaryTree.root->right = new TreeNode(15);
    binaryTree.root->left->left = new TreeNode(2);
    binaryTree.root->left->right = new TreeNode(7);
    binaryTree.root->right->left = new TreeNode(12);
    binaryTree.root->right->right = new TreeNode(20);

    // Check if the binary tree is a BST
    if (binaryTree.isBST()) {
        std::cout << "The given binary tree is a BST." << std::endl;
    } else {
        std::cout << "The given binary tree is not a BST." << std::endl;
    }

    // Cleanup (deallocate memory)
    // Note: In a real application, you would need to implement a proper destructor to free the memory.
    delete binaryTree.root->right->right;
    delete binaryTree.root->right->left;
    delete binaryTree.root->right;
    delete binaryTree.root->left->right;
    delete binaryTree.root->left->left;
    delete binaryTree.root->left;
    delete binaryTree.root;

    return 0;
}