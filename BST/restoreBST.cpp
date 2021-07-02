#include<iostream>
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

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp; 
};

void calcPointer(node* root, node* &first, node* &mid, node* &last, node* &previous) {
    if(root == NULL) {
        return;
    }
    calcPointer(root->left, first, mid, last, previous);
    if(previous && root->data < previous->data) {
        if(!first) {
            first = previous;
            mid = root;
        } else {
            last = root;
        }
    }
    previous = root;
    calcPointer(root->right, first, mid, last, previous);
};

node* restoreBST(node* root) {
    if(root == NULL) {
        return NULL;
    }
    node* first, *mid, *last, *previous;
    first = NULL;
    mid = NULL;
    last = NULL;
    previous = NULL;
    
    calcPointer(root, first, mid, last, previous);

    if(first && last) {
        swap(first->data, last->data);
    } else {
        swap(first->data, mid->data);
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
}


int main() {
    node* root = new node(4);
    root->left = new node(6);
    root->right = new node(2);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);

    inOrderPrint(root);
    cout<<endl;
    root = restoreBST(root);
    inOrderPrint(root);

    return 0;
}
