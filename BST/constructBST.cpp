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

// Here we use preOrderIdx by reference:
node* constructBST(int preOrder[], int &preOrderIdx, int key, int min, int max, int n) {
    if(preOrderIdx >= n) {
        return NULL;
    }

    node* root = NULL;
    if(key > min && key < max) {
        root = new node(key);
        preOrderIdx = preOrderIdx + 1;

        if(preOrderIdx < n) {
            root->left = constructBST(preOrder, preOrderIdx, preOrder[preOrderIdx], min, key, n);
        }
        if(preOrderIdx < n) {
            root->right = constructBST(preOrder, preOrderIdx, preOrder[preOrderIdx], key, max, n);
        }
    }
    return root;
};

void preOrderPrint(node* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

int main() {
    int preOrder[] = {4, 2, 1, 3, 6, 5, 7};
    int n = 7;
    int preOrderIdx = 0;
    int min = INT_MIN;
    int max = INT_MAX;
    int key = 4;
    
    node* root = constructBST(preOrder, preOrderIdx, key, min, max, n);
    preOrderPrint(root);
    return 0;
}
