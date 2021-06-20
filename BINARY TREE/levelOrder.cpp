#include<bits/stdc++.h>
#include<queue>
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

void levelOrder(node* root) {
    if(root == NULL) {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* newNode = q.front();
        q.pop();

        if(newNode != NULL) {
            cout<<newNode->data<<" ";
            if(newNode->left != NULL) {
                q.push(newNode->left);
            }
            if(newNode->right != NULL) {
                q.push(newNode->right);
            }
        } else {
            if(!q.empty()) {
                q.push(NULL);
            }
        }
    }
    
};

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    levelOrder(root);
    
    return 0;
}
