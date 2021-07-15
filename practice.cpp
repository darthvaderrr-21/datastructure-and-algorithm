#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

node* reverseK(node* &head, int k) {
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;

    while(count < k && currptr != NULL) {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr != NULL) {
        head->next = reverseK(nextptr, k);
    }

    return prevptr;
}

void display(node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);

    node* newNode = reverseK(head, 2);

    display(newNode);

    return 0;
}
