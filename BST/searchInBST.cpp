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

node* insertInBST(node* root, int val) {
    if(root == NULL) {
        return new node(val);
    }
    if( val < root->data) {
        root->left = insertInBST(root->left, val);
    } else {
        root->right = insertInBST(root->right, val);
    }
    return root;
};

void inOrderPrint(node* root) {
    if(root == NULL) {
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
};

node* searchInBST(node* root, int key) {
    if(root == NULL) {
        return NULL;
    }
    if( key == root->data) {
        return root;
    }
    else if(key < root->data) {
        return searchInBST(root->left, key);
    } else {
        return searchInBST(root->right, key);
    }
}

int main() {
    node* root = NULL;
    root = insertInBST(root, 5);
    insertInBST(root, 1);
    insertInBST(root, 3);
    insertInBST(root, 4);
    insertInBST(root, 2);
    insertInBST(root, 6);

    node* searchNode = searchInBST(root, 6);
    if(searchNode) {
        cout<<"Found";
    } else {
        cout<<"Not found!";
    }

    // inOrderPrint(root);

    return 0;
}
