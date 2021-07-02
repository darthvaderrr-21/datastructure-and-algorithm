#include<bits/stdc++.h>
#include<stack>
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

void swap(stack<node*> &a, stack<node*> &b) {
    stack<node*> temp = a;
    a = b;
    b = temp;
};

void zigzagTraversal(node* root) {
    if(root == NULL) {
        return;
    }

    stack<node*> currLevel;
    stack<node*> nextLevel;
    bool leftToRight = true;

    currLevel.push(root);

    while(!currLevel.empty()) {
        node* temp = currLevel.top();
        currLevel.pop();

        if(temp) {
            cout<<temp->data<<" ";

            if(leftToRight) {
                if(temp->left) {
                   nextLevel.push(temp->left); 
                }
                if(temp->right) {
                   nextLevel.push(temp->right);
                }
                
            }
            else {
                if(temp->right) {
                   nextLevel.push(temp->right);
                }
                if(temp->left) {
                   nextLevel.push(temp->left); 
                }
            }
        }

        if(currLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
};

void inOrderPrint(node* root) {
    if(root == NULL) {
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
};

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
    zigzagTraversal(root);

    return 0;
}
