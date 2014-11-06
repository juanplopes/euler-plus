#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define LIM 10000010
#define ull long long
using namespace std;

ull W[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
bool sieve[LIM];
vector<int> P;
ull T[LIM];


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

bool is_prime(ull n) {
    if (n>=LIM) {
        for(int i=0; i<7; i++) {
            if (witness(W[i]%n, n)) 
                return false;
        }
                
        return true;
    }
    if (n==1) return false;
    if (n==2) return true;
    if (n%2==0) return false;
    return !sieve[(n-3)/2];
}

int main() {
    make_sieve(LIM, 1<<16);
    make_primes();

    for(int i=0; i<P.size(); i++) {
        T[i+1] = T[i] + P[i];
    }
    int cases; cin >> cases;
    ull n;
    while(cin >> n) {
        int k = upper_bound(T, T+P.size()+1, n)-T;

        int maxk = 0;
        ull maxv = 0;
        for(int i=0; i<200; i++) {
            for(int j=-200; j<200; j++) {
                if (k+j <= i) continue;
                ull current = T[k+j]-T[i];
                if (current <= n and is_prime(current) and k+j-i > maxk) {
                    maxv = current;
                    maxk = k+j-i;
                }   
            }
        }
        
        cout << maxv << " " << maxk << endl;
    }

}

