#include <iostream>
#include <cstring>
#define LIM 20100
#define LIM2 200
using namespace std;

struct Num {
    int T[LIM];
    int sz;
    Num(int n) { T[0] = n; sz=0; }
    
    void add(Num &b) {
        int carry = 0;
        for(int i=0; i<=max(sz, b.sz) or carry; i++) {
            T[i] = (i<=sz ? T[i] : 0) + b.T[i] + carry;
            carry = T[i]/10;
            T[i]%=10;
            sz = max(sz, i);
        }
    }
    
    void print() {
        for(int i=sz; i>=0; i--) {
            cout << T[i];
        }
    }
};

int main() {
    int n;
    while(cin >> n) {
        Num N(1), D(2), C(0);
        for(int i=1; i<=n; i++) {
            C.sz = 0; C.T[0] = 0;
            C.add(N);
            C.add(D);
            if (C.sz > D.sz)
                cout << i << endl;
            C.add(D);
            N = D;
            D = C;
        }
    }
}

