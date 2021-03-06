#include <iostream>
#include <vector>
#include <cmath>
#define LIM 2000100
#define ull unsigned long long
using namespace std;

bool sieve[LIM];
vector<int> P;
int P10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

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
    for(int i=0; i<LIM; i++) {
        if (!sieve[i])
            P.push_back(i*2+3);
    }
}

bool is_prime(int n) {
    if (n%2==0) return false;
    return !sieve[(n-3)/2];
}

int rotate(int n, int log) {
    return n/10+P10[log]*(n%10);
}

bool is_circular(int n) {
    int log = (int)log10(n);
    for(int d=rotate(n, log); d!=n; d=rotate(d, log)) {
        if (!is_prime(d)) 
            return false;
    } 
    return true;
}

int main() {
    make_sieve(LIM, 1<<16);
    make_primes();
    int n;

    while(cin >> n) {
        int total = 0;
        for(int i=0; P[i]<n; i++)
            if (is_circular(P[i])) {
                total += P[i];
            }
        cout << total << endl;
    }
}
