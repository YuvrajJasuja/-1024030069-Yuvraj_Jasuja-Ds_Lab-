#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

void inorder(TreeNode* root) {
    if(root==nullptr){return;}
    cout<<root->data<<" ";
    inorder(root->right);
    inorder(root->left);
    inorder(root->right);
   
    
}

int main() {
    // Creating a sample tree
    /*
            10
           /  \
          5    15
         / \     \
        2   7     20
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(20);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
