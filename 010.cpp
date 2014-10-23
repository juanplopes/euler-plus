#include <iostream>
#include <map>
#include <cmath>
#define LIM 1001000
#define ull unsigned long long
using namespace std;

bool sieve[LIM];
map<int, ull> P;

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
    ull sum = 2;
    P[2] = sum;
    for(int i=0; i<LIM; i++) {
        if (!sieve[i]) {
            int p = i*2+3;
            P[p] = sum+=p;
        }
    }
}

int main() {
    make_sieve(LIM, 1<<16);
    make_primes();
    ull cases, n; cin >> cases;

    while(cin >> n) {
        map<int,ull>::iterator it = P.lower_bound(n);
        if (it->first != n)
            it--;
        cout << it->second << endl;
    }
}
