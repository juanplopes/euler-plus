#include <iostream>
#include <sys/types.h>
#define ull long long
using namespace std;

ull W[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

inline ull mul(__uint128_t a, __uint128_t b, __uint128_t c) {
    //a hack
    return a*b%c;
}

inline ull pow(ull a, ull n, ull mod) {
    ull r=1, p=a;
    while(n) {
        if (n&1) r=mul(r, p, mod);
        p=mul(p, p, mod);
        n>>=1;
    }
    return r;
}

bool witness(ull a, ull n) {
    if (a==0) return false;
    ull u=n/2, t=1;
    while(u%2==0) {
        u/=2; t++;
    }
    
    ull prev=pow(a,u,n), curr=0;
    
    for(int i=0;i<t;i++) {
        curr=mul(prev, prev, n);
        if (curr==1 and prev!=1 and prev!=n-1) return true;
        prev = curr;
    }
    return curr != 1;
}

bool is_prime(ull n) {
    for(int i=0; i<7; i++) {
        if (witness(W[i]%n, n)) 
            return false;
    }
            
    return true;
}

ull solve(ull n) {
    ull x=1, p=0;
    for(ull side=3; side<1000000; side+=2) {
        for(int i=0; i<4; i++) {
            if (x>x+side) cout << side << endl;
            x+=side-1;
            if (is_prime(x)) p++;
        }
        
        if (p*100 < n*(2*side-1)) {
            return side;
        }
    }
    return -1;
}

int main() {
    int n;
    while(cin >> n) {
        cout << solve(n) << endl; 
    }
}
