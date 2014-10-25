#include <iostream>
#include <set>
#define ull unsigned long long
using namespace std;

int T[1001000];
set<int> S;

int seq(ull n) {
    if (n<1001000 and T[n]) return T[n];
    if (n==0) return 1;
    if (n==1) return 0;
    
    int d;
    if (n&1) d = seq(n*3+1)+1;
    else     d = seq(n/2)+1;
    if (n<1001000) T[n] = d;
    return d;
}

int main() {
    int maxx = -1;
    for(int i=1; i<=5000000; i++) {
        int d = seq(i);
        if (d >= maxx) {
            S.insert(i);
            maxx = d;      
        }
    }
    
    int cases, n; cin >> cases;
    while(cin >> n) {
        set<int>::iterator it = S.lower_bound(n);
        if (*it!=n) it--;
        cout << *it << endl;
    }

}
