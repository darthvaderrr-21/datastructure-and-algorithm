#include<bits/stdc++.h>
#include<string>
#include<stack>
using namespace std;

int precedence(char c) {
    if(c == '^') {
        return 3;
    } else if(c == '*' || c == '/') {
        return 2;
    } else if(c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
};

string reverseStr(string s) {
    stack<char> st;
    string str;

    for(int i=0; i<s.length(); i++) {
        st.push(s[i]);
    }

    while(!st.empty()) {
        if(st.top() == '(') {
            st.top() = ')';
            str += st.top();
            st.pop();
        } else if(st.top() == ')') {
            st.top() = '(';
            str += st.top();
            st.pop();
        } else {
            str += st.top();
            st.pop();
        }
    }
    return str;
};

string infixToPostfix(string s) {
    s = reverseStr(s);
    string res = "";
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) {
            res += s[i];
        } 
        else if(s[i] == '(') {
            st.push(s[i]);
        } 
        else if(s[i] == ')') {
            while(!(st.empty()) && (st.top() != '(')) {
                res += st.top();
                st.pop();
            }
            if(!st.empty()) {
                st.pop();
            }
        } 
        else {
            while(!(st.empty()) && precedence(st.top()) > precedence(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    if(!st.empty()) {
        res += st.top();
    }
    res = reverseStr(res);
    return res;
}

int main() {
    string s = "(a-b/c)*(a/k-l)";
    cout<<infixToPostfix(s);

    return 0;
}
