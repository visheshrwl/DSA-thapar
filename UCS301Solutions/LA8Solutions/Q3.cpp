#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void deleteKey(int key) {
        root = deleteRec(root, key);
    }

    int maxDepth() {
        return maxDepthRec(root);
    }

    int minDepth() {
        return minDepthRec(root);
    }

private:
    TreeNode* insertRec(TreeNode* root, int key) {
        if (root == nullptr) {
            return new TreeNode(key);
        }

        if (key < root->data) {
            root->left = insertRec(root->left, key);
        } else if (key > root->data) {
            root->right = insertRec(root->right, key);
        }

        return root;
    }

    TreeNode* deleteRec(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->data) {
            root->left = deleteRec(root->left, key);
        } else if (key > root->data) {
            root->right = deleteRec(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* temp = findMinRec(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }

        return root;
    }

    int maxDepthRec(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = maxDepthRec(node->left);
        int rightDepth = maxDepthRec(node->right);

        return 1 + std::max(leftDepth, rightDepth);
    }

    int minDepthRec(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = minDepthRec(node->left);
        int rightDepth = minDepthRec(node->right);

        return 1 + std::min(leftDepth, rightDepth);
    }

    TreeNode* findMinRec(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

int main() {
    BST bst;

    // Insert elements
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    for (int element : elements) {
        bst.insert(element);
    }

    // Display maximum and minimum depth
    std::cout << "Maximum Depth of BST: " << bst.maxDepth() << std::endl;
    std::cout << "Minimum Depth of BST: " << bst.minDepth() << std::endl;

    // Delete an element
    int elementToDelete = 30;
    std::cout << "Deleting element " << elementToDelete << std::endl;
    bst.deleteKey(elementToDelete);

    // Display maximum and minimum depth after deletion
    std::cout << "Maximum Depth of BST after deletion: " << bst.maxDepth() << std::endl;
    std::cout << "Minimum Depth of BST after deletion: " << bst.minDepth() << std::endl;

    return 0;
}
