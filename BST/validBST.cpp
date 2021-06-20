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

bool isValidBST(node* root, int min, int max) {
    if(root == NULL) {
        return true;
    }
    if((root->data <= min && min != NULL) || (root->data >= max && max != NULL)) {
        return false;
    } else {
        bool leftValid = isValidBST(root->left, min, root->data);
        bool rightValid = isValidBST(root->right, root->data, max);

        return leftValid && rightValid;
    }
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

    if(isValidBST(root, NULL, NULL)) {
        cout<<"Valid BST"<<endl;
    } else {
        cout<<"Invalid BST!"<<endl;
    }

    // inOrderPrint(root);

    return 0;
}
