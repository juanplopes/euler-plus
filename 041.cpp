#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#define LIM 10000010
#define ull unsigned long long
using namespace std;

bool sieve[LIM];
vector<int> P;
set<ull> S;
int T[9];

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

inline bool is_prime(ull n) {
    if (n==1) return false;
    if (n==2) return true;
    if (n%2==0) return false;
    return !sieve[(n-3)/2];
}

int main() {
    make_sieve(LIM, 1<<16);
    make_primes();

    for(int i=3; i<=7; i++) {
        for(int j=0; j<i; j++)
            T[j] = j+1;

        while(next_permutation(T, T+i)) {
            ull sum = 0;
            for(int j=0; j<i; j++)
                sum = sum*10+T[j];
            if (is_prime(sum)) {
                S.insert(sum);
            }
        }
    }

    int cases; cin >> cases;
    ull n;
    while(cin >> n) {
        set<ull>::iterator it = S.lower_bound(n);
        if (*it != n) {
            if (it == S.begin())
                cout << -1 << endl;
            else
                cout << *(--it) << endl;
        } else {
            cout << *it << endl;
        }
    }

}

