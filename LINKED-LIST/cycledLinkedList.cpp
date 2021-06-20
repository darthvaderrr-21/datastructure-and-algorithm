#include<iostream>
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

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
};

void insertAtTail(node* &head, int val) {
    node* n = new node(val);
    if(head == NULL) {
        head=n;
        return;
    };

    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
};

void display(node* head) {
    node* temp = head;
    while(temp->next != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
};

void makeCycle(node* &head, int pos) {
    node* temp = head;
    node* setnode;
    int count = 1;

    while(temp->next != NULL) {
        if(count == pos) {
            setnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = setnode;
};

int detectCycle(node* head) {
    node* fast = head;
    node* slow = head;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) {
            return true;
        }
    }
    return false;
};

void removeCycle(node* &head) {
    node* fast = head;
    node* slow = head;

    do {
        fast = fast->next->next;
        slow = slow->next;
    } while(fast != slow);

    fast = head;
    while(fast->next != slow->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
};

int main() {
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    makeCycle(head, 3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);

    return 0;
}
