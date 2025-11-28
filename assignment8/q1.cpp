#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d){ data=d; left=right=NULL; }
};

Node* insert(Node* root, int data){
    if(root == NULL) return new Node(data);
    if(data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = NULL;
    root = insert(root, 40);
    insert(root, 20);
    insert(root, 60);
    insert(root, 10);
    insert(root, 30);

    cout << "Preorder: "; preorder(root);
    cout << "\nInorder: "; inorder(root);
    cout << "\nPostorder: "; postorder(root);
}
