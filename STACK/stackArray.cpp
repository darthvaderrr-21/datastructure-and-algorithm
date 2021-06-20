#include<iostream>
using namespace std;

#define n 100

class stack {
    int* arr;
    int top;

    public:
    stack() {
        arr = new int[n];
        top = -1;
    }

    void push(int val) {
        if(top == n-1) {
            cout<<"Stack overflow!";
            return;
        }
        top++;
        arr[top] = val;
    };

    void pop() {
        if(top == -1) {
            cout<<"NO Element to pop!"<<endl;
            return;
        }
        top--;
    };

    int Top() {
        if(top==-1) {
            cout<<"Empty stack!"<<endl;
            return -1;
        }
        return arr[top];
    };

    bool empty() {
        return (top == -1);
    }
};

int main() {
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();

    return 0;
}
