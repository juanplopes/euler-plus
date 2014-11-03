#include <iostream>
#include <sys/types.h>
#define ull long long
using namespace std;

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

int main() {
    int n;
    while(cin >> n) {
        ull res = 0;
        for(int i=1; i<=n; i++) {
            res += pow(i, i, 10000000000ll);
            res %= 10000000000ll;
        }
        cout << res << endl;
    }
}
