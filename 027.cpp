#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#define LIM 100000
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

bool is_prime(int n) {
    if (n<0) return false;
    return !sieve[(n-3)/2];
}

int main() {
    make_sieve(LIM, 1<<16);
    make_primes();
 
    int n;
    while(cin >> n) {
        int maxx = 0, aa, bb;
        for(int a=-n; a<n; a++) {
            for(int bi=0; bi<P.size() and P[bi]<=n; bi++) {
                int b = P[bi];
                if (b<=maxx) continue;

                int count=0;
                for(int i=0;i<b;i++) {
                    if(!is_prime(i*i+a*i+b)) break;
                    count++;
                }

                if (count>maxx) {
                    maxx = count;
                    aa = a;
                    bb = b;
                }
            }
        }
    
        cout << aa << " " << bb << endl;
    }
}
