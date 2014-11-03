#include <iostream>
#include <cmath>
#include <set>
#define ull long long
using namespace std;

set<ull> S[7];

bool tri(ull n) {
    double x = (sqrt(1+8*n)-1)/2;
    return abs(x-round(x)) < 1e-8;
}

bool hex(ull n) {
    double x = (1+sqrt(1+8*n))/4;
    return abs(x-round(x)) < 1e-8;
}


int main() {
    for(ull n=1, a=4; n<200000000000000ll; n+=a, a+=3) {
        if (tri(n))
            S[5].insert(n);
         if (hex(n))
            S[6].insert(n);
    }
    
    ull n, a, b;
    while(cin >> n >> a >> b) {
        set<ull>::iterator limit = S[b].lower_bound(n);
        for(set<ull>::iterator it = S[b].begin(); it!=limit; it++)
            cout << *it << endl;
    }
    
}

