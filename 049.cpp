#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define LIM 2000010
#define pii pair<int,int>
using namespace std;

bool sieve[LIM];
vector<int> P;
map<int, vector<int> > T;
int TEMP[10];
vector<pii> A;

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

int sortn(int n) {
    while(n) {
        TEMP[n%10]++;
        n/=10;
    }
    for(int i=9; i>=0; i--)
        for(;TEMP[i];TEMP[i]--)
            n = (n*10)+i;        

    return n;
}

int main() {
    make_sieve(LIM, 1<<16);
    make_primes();

    for(int i=0; i<P.size(); i++) {
        T[sortn(P[i])].push_back(P[i]);
    }

    int cases, n, k;
    while(cin >> n >> k) {
        A.clear();
        map<int, vector<int> >::iterator it = T.begin();
        for(;it!=T.end();it++) {
            vector<int> V = it->second;
            for(int i=0; i<V.size() and V[i] < n; i++) {
                for(int j=i+1; j<V.size(); j++) {
                    int diff = V[j] - V[i];
                    if (count(V.begin(), V.end(), V[j]+diff) and (k==3 or count(V.begin(), V.end(), V[j]+2*diff)))                     
{
                        A.push_back(pii(V[i], diff));
                    }
                }
            }
                
        }
        
        sort(A.begin(), A.end());
        for(int i=0; i<A.size(); i++) {
            int first = A[i].first;
            int diff = A[i].second;
            cout << first << first+diff << first+2*diff;
            if (k==4)
                cout << first+3*diff;
            cout << endl;
        }
    }

}

