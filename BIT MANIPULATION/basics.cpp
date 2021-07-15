#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos) {
    return n & (1<<pos);
}

int setBit(int n, int pos) {
    return n | (1<<pos);
}

int clearBit(int n, int pos) {
    return n & (~(1<<pos));
}

int updateBit(int n, int pos, int bit) {
    int m = clearBit(n, pos);

    return m | (bit<<pos);
}

int main() {
    
    return 0;
}
