#include <iostream>
#include <set>
#include <cmath>
using namespace std;

struct Frac {
    int a, b;
    Frac(int a, int b) : a(a), b(b) {}
    inline bool operator < (const Frac& other) const {
        if (a!=other.a) return a<other.a;
        if (b!=other.b) return b<other.b;
        return false;
    }
};

set<Frac> S[5][4];
int P[6] = {1, 10, 100, 1000, 10000, 100000};

inline void ok(double value, int a, int b, int n, int k, int pak, int man) {
    if (n>man) return;
    if (k>=1 and abs((double)a/b-value)<1e-8 and ceil(log10(a+1))==n and ceil(log10(b+1))==n) {
        
        S[n][k].insert(Frac(a, b));
    }
    if (n==man) return;
    
    int limit = P[n];
    for(int i=1;i<10;i++)
        for(int pa=pak; pa<=limit; pa*=10)
            for(int pb=1; pb<=limit; pb*=10) {
                ok(value, a/pa*pa*10+pa*i+a%pa, b/pb*pb*10+pb*i+b%pb, n+1, k+1, pa*10, man);
            }
}

int main() {
    int n, k;
    while(cin >> n >> k) {
        int mb=P[n-k];
        for(int i=1; i<mb; i++) {
            for(int j=i+1; j<mb; j++) {
                ok((double)i/j, i, j, n-k, 0, 1, n);
            }
        }

        set<Frac>::iterator it = S[n][k].begin();
        int ta=0, tb=0;
        for(;it!=S[n][k].end();it++) {
//            cout << " " << it->a << "/" << it->b << endl;
            ta+=it->a;
            tb+=it->b;
        }  
        cout << ta << " " << tb << endl;
    }

}

