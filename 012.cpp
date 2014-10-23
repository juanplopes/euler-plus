#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#define LIM 100100
#define ull unsigned long long
using namespace std;

bool sieve[LIM];
vector<int> P;
map<int, int> R;

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

int divisors_count(int n) {
    int upper = (int)sqrt(n);

    ull result = 1;
    for(int i=0; i<P.size() && P[i] <= upper; i++) {
        int count = 1;
        while (n%P[i]==0) {
            n /= P[i];
            count++;
        }
        result *= count;
    }
    if (n > 1) 
        result *= 2;
    return result;
}

int main() {
    make_sieve(LIM, 1<<16);
    make_primes();

    int maxx = 0;
    for(int i=2; i<45000;i++) {
        int x = i*(i+1)/2;
        int d = divisors_count(x);
        if (d > maxx) {
            R[d] = x;
            maxx = d;
        }
    }

    ull cases, n; cin >> cases;
    while(cin >> n) {
        cout << R.upper_bound(n)->second << endl;
    }
}
