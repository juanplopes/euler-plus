#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#define LIM 10001
using namespace std;

bool sieve[LIM];
vector<int> P;
set<int> S;

void make_sieve(int until, int step) {
    until++;
    int n = (until - 3) / 2;
    int limit = (int)sqrt(n);

    for (int b = 0; b < n; b += step)
    {
        int end = min(n, b + step);
        for (int i = 0; i < limit; i++)
        {
            int k = i * 2 + 3;
            int kk = (k * k - 3) / 2;

            int  start = (b-i) / k * k + i;
            if (start < b) start += k;
            if (start < kk) start = kk;

            if (!sieve[i]) {
                for (int j = start; j < end; j += k)
                    sieve[j] = true;
            }
        }
    }
}

void make_primes() {
    P.push_back(2);
    for(int i=0; i<(LIM-3)/2; i++) {
        if (!sieve[i])
            P.push_back(i*2+3);
    }
}

int rec(int d) {
    int r=1, c=0;
    while(true) {
        while(r<d) r*=10;
        c++;
        r%=d;
        if (r==0) return -1;
        if (r==1) return c;
    }
    return c;
}

int main() {
    make_sieve(LIM, 1<<16);
    make_primes();
 
    int maxx=-1;
    for(int i=0; i<P.size(); i++) {
        int r = rec(P[i]);
        if (r > maxx) {
            maxx = r;
            S.insert(P[i]);
        }
    }
    
    
    int cases, n; cin >> cases;
    while(cin >> n) {
        set<int>::iterator it = S.lower_bound(n);
        it--;
        cout << *it << endl;
    }
}
