#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* inOrderSucc(node* root) {
    node* curr = root;
    while(curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

node* deleteInBST(node* root, int key) {
    if(root == NULL) {
        return NULL;
    }
    
    if(key < root->data) {
        root->left = deleteInBST(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteInBST(root->right, key);
    }
    else {
        if(root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = inOrderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

void inOrderPrint(node* root) {
    if(root == NULL) {
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}

int main() {
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);

    inOrderPrint(root);
    cout<<endl;
    root = deleteInBST(root, 4);
    inOrderPrint(root);
    cout<<endl;
    
    return 0;
}
