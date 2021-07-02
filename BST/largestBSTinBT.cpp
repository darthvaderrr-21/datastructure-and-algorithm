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

struct info {
    int size;
    int ans;
    int min;
    int max;
    bool isBST;
};

info largestBST(node* root) {
    if(root == NULL) {
        return {0, 0, INT_MIN, INT_MAX, true};
    }
    else if( root->left == NULL && root->right == NULL) {
        return {1, 1, root->data, root->data, true};
    }
    else {
        info leftInfo = largestBST(root->left);
        info rightInfo = largestBST(root->right);

        info curr;
        curr.size = 1 + leftInfo.size + rightInfo.size;

        if(leftInfo.isBST && rightInfo.isBST && root->data > leftInfo.max && root->data < rightInfo.min) {
            curr.ans = curr.size;
            curr.min = min(root->data, min(leftInfo.min, rightInfo.min));
            curr.max = max(root->data, max(leftInfo.max, rightInfo.max));
            curr.isBST = true;

            return curr;
        }

        curr.ans = max(leftInfo.ans, rightInfo.ans);
        curr.isBST = false;

        return curr;
    }
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
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);    

    inOrderPrint(root);
    cout<<endl;
    cout<<largestBST(root).ans;
    
    return 0;
}