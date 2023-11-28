
#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;
    BST(){
        root = NULL;
    }

    void insert(int data){
        root = _insert(root, data);
    }
    TreeNode *_insert(TreeNode *root, int data)
    {
        if (root == NULL){
            return new TreeNode(data);
        }
        if (data < root->data){
            root->left = _insert(root->left, data);
        } else if (data > root->data){
            root->right = _insert(root->right, data);
        }
        return root;
    }
    int findmin(){
        return findMinNode(root);
    }

    TreeNode* inOrderSuccessor(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        // If the node has a right subtree
        if (node->right != nullptr) {
            return findMinRec(node->right);
        }

        // If the node does not have a right subtree
        TreeNode* successor = nullptr;
        TreeNode* current = root;

        while (current != nullptr) {
            if (node->data < current->data) {
                successor = current;
                current = current->left;
            } else if (node->data > current->data) {
                current = current->right;
            } else {
                break;
            }
        }
        return successor;
    }

 TreeNode* inOrderPredecessor(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        // If the node has a left subtree
        if (node->left != nullptr) {
            return findMaxRec(node->left);
        }

        // If the node does not have a left subtree
        TreeNode* predecessor = nullptr;
        TreeNode* current = root;

        while (current != nullptr) {
            if (node->data > current->data) {
                predecessor = current;
                current = current->right;
            } else if (node->data < current->data) {
                current = current->left;
            } else {
                break;
            }
        }

        return predecessor;
    }

    int findMinNode(TreeNode *root){
        if(root == NULL){
            cout << "error: Tree is empty" << endl;
        }
        while(root->left != NULL){
            root = root->left;
        }
        return root->data;
    }

    int findMax(){
        return findMaxNode(root); 
    }

    int findMaxNode(TreeNode *root){
        if (root == NULL){
            cout << "Error: Tree is Empty." << endl;
            return -1;
        }
        while (root->right != NULL){
            root = root->right;
        }
        return root->data;
    };

    private:
        TreeNode* findMinRec(TreeNode* node){
            while(node->left != NULL){
                node=node->left;
            }
            return node;
        }

        TreeNode* findMaxRec(TreeNode* node) {
            while (node->right != nullptr) {
                node = node->right;
            }
        return node;
    }
};

TreeNode *searchRecursive(TreeNode *root, int data)
{
    if (root == NULL || root->data == data){return root;}

    if (data < root->data){ 
        return searchRecursive(root->left, data);
    }
    return searchRecursive(root->right, data);
}

TreeNode *searchNonRecursive(TreeNode *root, int data)
{
    TreeNode *current = root;

    while (current != NULL){
        if (data == current->data){
            return current;
        } else if (data < current->data){
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}

int main()
{
    BST bst;
    int datas[] = {5, 3, 8, 2, 4, 7, 9};
    for (int data : datas){
        bst.insert(data);
    }

    int maxElement = bst.findMax();
    cout << "Maximum element in the Tree" << maxElement<<endl;

    int minElement = bst.findmin();
    cout << "Minimum element in the Tree" << minElement <<endl;

    TreeNode *resultRecursive = searchRecursive(bst.root, 4);
    if (resultRecursive){
        cout << "Key fuond recursively" << resultRecursive->data << endl;
    }
    else{
        cout << "Key not found recursively" << endl;
    }

    TreeNode *resultNonRecursive = searchNonRecursive(bst.root, 7);

    if (resultNonRecursive){
        cout << "Key found non-recursively" << resultNonRecursive->data;
    } else {
        cout << "Key not found" << endl;
    }

        TreeNode* successorNode = bst.inOrderSuccessor(resultNonRecursive);
    if (successorNode) {
        std::cout << "In-order successor of " << resultNonRecursive->data << " is " << successorNode->data << std::endl;
    } else {
        std::cout << "No in-order successor found for " << resultNonRecursive->data << std::endl;
    }

    TreeNode* predecessorNode = bst.inOrderPredecessor(resultNonRecursive);
    if (predecessorNode) {
        std::cout << "In-order predecessor of " << resultNonRecursive->data << " is " << predecessorNode->data << std::endl;
    } else {
        std::cout << "No in-order predecessor found for " << resultNonRecursive->data << std::endl;
    }

    return 0;
}