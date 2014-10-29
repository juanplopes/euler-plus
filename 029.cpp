#include <iostream>
#include <map>
#include <vector>
#define ull unsigned long long
using namespace std;

map<int, int> P;

long gcd(long a, long b) {
    while(b) {
        long c = a%b;
        a = b;
        b = c;
    }
    return a;
}

ull repeated(int power, int n) {
    int total = n/power-1;
    for(int i=n/power+1; i<=n; i++) {
        bool cut = false;
        for(int step=1; step<power and !cut; step++)
            cut = cut || (i<=n*step/power and i%(step/gcd(step, power))==0);
        if (cut) total++;
    }
    return total;
}

int main() {
    for(int i=2;i<1000; i++) {
        int p = i*i;
        for(int j=2; p<=200000; j++) {
            if (!P.count(p))
                P[p] = j;
            p *= i;
        }
    }
    
    ull n;
    while(cin >> n) {
        map<int, int>::iterator it = P.begin();
    
        ull total = (n-1)*(n-1);
        for(;it->first<=n;it++) {
            total -= repeated(it->second, n);
        }
        cout << total << endl;
    }

}

