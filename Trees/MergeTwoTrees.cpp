#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void inorder(Node* root, stack<Node*>& s) {
    if (!root) {
        return;
    }
    inorder(root->right, s);
    s.push(root);
    inorder(root->left, s);
}

Node* merge(Node* root1, Node* root2) {
    stack<Node*> s1, s2;
    inorder(root1, s1);
    inorder(root2, s2);

    Node* head = NULL;
    Node* prev = NULL;

    while (!s1.empty() || !s2.empty()) {
        Node* curr;
        if (s1.empty()) {
            curr = s2.top();
            s2.pop();
        } else if (s2.empty()) {
            curr = s1.top();
            s1.pop();
        } else if (s1.top()->data < s2.top()->data) {
            curr = s1.top();
            s1.pop();
        } else {
            curr = s2.top();
            s2.pop();
        }

        if (!head) {
            head = curr;
        } else {
            prev->right = curr;
            curr->left = prev;
        }
        prev = curr;
    }

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    Node* root1 = newNode(5);
    root1->left = newNode(3);
    root1->right = newNode(7);
    root1->left->left = newNode(2);
    root1->left->right = newNode(4);

    Node* root2 = newNode(10);
    root2->left = newNode(8);
    root2->right = newNode(12);
    root2->left->left = newNode(6);
    root2->left->right = newNode(9);

    Node* head = merge(root1, root2);

    printList(head);

    return 0;
}