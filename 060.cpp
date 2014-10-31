#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define LIM 10000010
#define ull unsigned long long
using namespace std;

bool sieve[LIM];
vector<int> P;
ull W[] = {2, 7, 61};
int P10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
bool PP[3000][3000];
int LOG10[3000];
int B[5];
vector<int> A;

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

inline ull pow(ull a, ull n, ull mod) {
    ull r=1, p=a;
    while(n) {
        if (n&1) r=r*p%mod;
        p=p*p%mod;
        n>>=1;
    }
    return r;
}

bool witness(int a, int n) {
    if (a==0) return false;
    int u=n/2, t=1;
    while(u%2==0) {
        u/=2; t++;
    }
    
    ull prev=pow(a,u,n), curr=0;
    
    for(int i=0;i<t;i++) {
        curr=prev*prev%n;
        if (curr==1 and prev!=1 and prev!=n-1) return true;
        prev = curr;
    }
    return curr != 1;
}


inline bool is_prime(int n) {
    if (n>=LIM) {
        if (n==2 || n==7 || n==61) return true;
        
        if (witness(2, n)) return false;
        if (witness(7, n)) return false;
        if (witness(61, n)) return false;
        return true;
    }
    if (n==1) return false;
    if (n==2) return true;
    if (n%2==0) return false;
    return !sieve[(n-3)/2];
}

inline int ppp(int i, int j) {
    return PP[i][j];
//    return is_prime(P[i] * LOG10[j] + P[j]) and is_prime(P[j] * LOG10[i] + P[i]);
}

void backtrack(int dep, int n, int k, int nexti) {
    if (dep == k) {
        int sum = 0;
        for(int i=0; i<dep; i++)
            sum += P[B[i]];
        A.push_back(sum);
        return;
    }

    for(int i=nexti; i<P.size() and P[i] < n; i++) {
        bool cont = false;
        for(int j=0; !cont and j<dep; j++)
            if (not ppp(i, B[j]))
                cont = true;
        if (cont) continue;
        B[dep] = i;
        backtrack(dep+1, n, k, i+1);
    }
}

int main() {
    make_sieve(LIM, 1<<16);
    make_primes();

    for(int i=0; i<P.size() and P[i] < 20000; i++) {
        LOG10[i] = P10[(int)ceil(log10(P[i]+1))];
    }

    for(int i=0; i<P.size() and P[i] < 20000; i++) {
        for(int j=i+1; j<P.size() and P[j] < 20000; j++) {
            PP[i][j] = PP[j][i] = is_prime(P[i] * LOG10[j] + P[j]) and is_prime(P[j] * LOG10[i] + P[i]);
        }
    }
    
    int n, k;
    while(cin >> n >> k) {
        A.clear();
        backtrack(0, n, k, 0);
        sort(A.begin(), A.end());
        for(int i=0; i<A.size(); i++) {
            cout << A[i] << endl;
        }
    }
}
