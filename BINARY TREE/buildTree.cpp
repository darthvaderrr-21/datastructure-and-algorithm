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

void preOrderPrint(node* root)  {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
};

void inOrderPrint(node* root)  {
    if(root == NULL) {
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
};

void postOrderPrint(node* root)  {
    if(root == NULL) {
        return;
    }
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout<<root->data<<" ";
};;

int search(int inOrder[], int start, int end, int curr) {
    for(int i=start; i<=end; i++) {
        if(inOrder[i] == curr) {
            return i;
        }
    }
    return -1;
};

// Build Tree by PreOrder and InOrder sequence:

node* buildTree(int preOrder[], int inOrder[], int start, int end) {
    static int idx = 0;
    if(start > end) {
        return NULL;
    }
    int curr = preOrder[idx];
    idx++;
    node* root = new node(curr);
    if(start == end) {
        return root;
    }
    int pos = search(inOrder, start, end, curr);

    root->left = buildTree(preOrder, inOrder, start, pos-1);
    root->right = buildTree(preOrder, inOrder, pos+1, end);

    return root;
};

// =============================================================

// Build Tree by PostOrder and InOrder sequence:

// node* buildTree(int postOrder[], int inOrder[], int start, int end) {
//     int n = 7;
//     static int idx = n-1;
//     if(start > end) {
//         return NULL;
//     }
//     int curr = postOrder[idx];
//     node* root = new node(curr);
//     idx--;
//     if(start == end) {
//         return root;
//     }

//     int pos = search(inOrder, start, end, curr);
//     root->right = buildTree(postOrder, inOrder, pos+1, end);
//     root->left = buildTree(postOrder, inOrder, start, pos-1);

//     return root;
// }

// =============================================================


int main() {
    int preOrderArray[] = {1, 2, 4, 5, 3, 6, 7};
    int inOrderArray[] = {4, 2, 5, 1, 6, 3, 7};
    int postOrderArray[] = {4, 5, 2, 6, 7, 3, 1};
    
    node* root = buildTree(preOrderArray, inOrderArray, 0, 6);
    // node* root = buildTree(postOrderArray, inOrderArray, 0, 6);
    // preOrderPrint(root);
    postOrderPrint(root);

    return 0;
}
