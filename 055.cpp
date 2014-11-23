#include <iostream>
#include <cstring>
#include <map>
#include <sys/types.h>
#define LIM 101000
#define ull __uint128_t
using namespace std;

int T[LIM];
map<ull, int> M;

ull reverse(ull n) {
    ull x = 0;
    while(n) {
        x = x*10+n%10;
        n/=10;
    }
    return x;
}

int main() {
    int x;
    while(cin >> x) {
        M.clear();
        unsigned long long maxn, maxv=0;
        for(int i=1;i<=x; i++) {
            ull n = i;
            for(int j=0; j<60; j++) {
                ull r = reverse(n);
                if (r==n) {
                    if (++M[n] > maxv) {
                        maxv = M[n];
                        maxn = n;
                    }
                    break;
                }    
                n = r+n;
            }
        }
        cout << maxn << " " << maxv << endl;
    }
}

