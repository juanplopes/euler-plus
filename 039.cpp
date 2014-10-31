#include <iostream>
#include <cmath>
#include <set>
#define MAXX 5000100
using namespace std;

int T[MAXX];
set<int> S;

int gcd(int a, int b) {
    while(b) {
        int c = b;
        b = a%b;
        a = c;
    }
    return a;
}

int main() {
    for(int m=1; m<sqrt(MAXX); m++) {
        for(int n=m+1; n<sqrt(MAXX); n++) {
            if ((n+m)%2!=1 or gcd(m, n) != 1) continue;
            int a = n*n-m*m, b=2*m*n, c=n*n+m*m;
            if (a+b+c >= MAXX) break;
            
            int ka=0, kb=0, kc=0;
            for(int k=0; k<MAXX; k++) {
                ka+=a; kb+=b; kc+=c;
                if (ka+kb+kc >= MAXX) break;
                T[ka+kb+kc]++;
            }
        }
    }

    int maxx = 0;
    for(int i=0; i<MAXX; i++) {
        if (T[i] > maxx) {
            maxx = T[i];
            S.insert(i);
        }
    }

    int n, cases; cin >> cases;
    while(cin >> n) {
        set<int>::iterator it = S.lower_bound(n);
        if (*it != n) it--;
        cout << *it << endl;
    }

}

