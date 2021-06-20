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

int sumAtLevelK(node* root, int k) {
    if(root == NULL) {
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int sum = 0;
    int level = 0;

    while(!q.empty()) {
        node* newNode = q.front();
        q.pop();

        if(newNode != NULL) {
            if(level == k) {
                sum += newNode->data;
            }
            if(newNode->left != NULL) {
                q.push(newNode->left);
            }
            if(newNode->right != NULL) {
                q.push(newNode->right);
            }
        }
        else {
            if(!q.empty()) {
                q.push(NULL);
                level++;
            }
        }
    }
    return sum;
};

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<sumAtLevelK(root, 2);

    return 0;
}
