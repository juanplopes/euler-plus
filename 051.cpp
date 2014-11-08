#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define LIM 30000010
using namespace std;

bool sieve[LIM];
int P11[] = {1, 11, 11*11, 11*11*11, 11*11*11*11, 11*11*11*11*11, 11*11*11*11*11*11, 11*11*11*11*11*11*11};
int P12[] = {1, 10, 10*11, 10*11*11, 10*11*11*11, 10*11*11*11*11, 10*11*11*11*11*11, 10*11*11*11*11*11*11};

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


bool is_prime(int n) {
    if (n==1) return false;
    if (n==2) return true;
    if (n%2==0) return false;
    return !sieve[(n-3)/2];
}

int count10(int n) {
    int sum = 0;
    while(n) {
        if (n%11==10) sum++;
        n/=11;
    }
    return sum;
}

int replace(int n, int with) {
    int result = 0, p10 = 1;
    while(n) {
        int xx = n%11;
        if (xx==10) xx=with;
        result += p10*xx;
        p10*=10;
        n/=11;
    }
    return result;
}

bool countp(int n, int L, int start) {
    int sum = 0;
    for(int i=start; i<10; i++) {
        if (10-i<L-sum) return false;

        if (is_prime(replace(n, i)))
            sum++;
    }
    return sum >= L;
}

int main() {
    make_sieve(LIM, 1<<16);

    int n, k, L;
    while(cin >> n >> k >> L) {
        int sum = 0;
        
        int minn=0x3f3f3f3f, minp=0x3f3f3f3f;
        for(int i=P11[n-1]; i<P11[n]; i++) {
            if (count10(i) != k) continue;
            int start=i>=P12[n]?1:0;
            if (countp(i, L, start)) {
                for(int j=start; j<10; j++) {
                    int xx = replace(i, j);
                    if (xx < minp and is_prime(xx)) {
                        minn = i;
                        minp = xx;
                        break;
                    }
                }
            }
        }

        int count = 0;
        int start=minn>=P12[n]?1:0;
        for(int j=start; j<10 && count < L; j++) {
            int xx = replace(minn, j);
            if (is_prime(xx)) {
                cout << (count>0?" ":"") << xx;
                count++;
            }
        }
        cout << endl;

        
    }

}

