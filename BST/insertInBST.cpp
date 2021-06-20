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

node* insertBST (node* root, int val) {
    if(root == NULL) {
        return new node(val);
    }
    if(val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
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
    node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 6);

    inOrderPrint(root);

    return 0;
}
