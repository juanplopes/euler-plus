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
    if (n==1) return false;
    if (n==2) return true;
    if (n%2==0) return false;
    return !sieve[(n-3)/2];
}

int reverse(int n) {
    int res = 0;
    while(n) {
        res = res*10 + n%10;
        n/=10;
    }
    return res;
}

bool right(int n) {
    while(n) {
        if (!is_prime(n)) return false;
        n/=10;
    }
    return true;
}

bool left(int n) {
    while(n) {
        if (!is_prime(reverse(n))) return false;
        n/=10;
    }
    return true;
}


bool is_truncatable(int n) {
    return right(n) and left(reverse(n)); 
}

int main() {
    make_sieve(LIM, 1<<16);
    make_primes();
    int n;

    while(cin >> n) {
        int total = 0;
        for(int i=0; P[i]<n; i++)
            if (P[i] > 10 and is_truncatable(P[i])) {
                total += P[i];
            }
        cout << total << endl;
    }
}
