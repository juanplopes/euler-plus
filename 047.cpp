#include <iostream>
#include <set>
#define LIM 2000010
using namespace std;

int T[LIM];
set<int> A[5];
int main() {
    for(int i=2; i<LIM; i++) {
        if (T[i]) continue;
        for(int j=i*2; j<LIM; j+=i)
            T[j]++;
    }
    
    for(int i=1; i<LIM-4; i++) {
        for(int j=2; j<=4; j++) {
            bool ok = true;
            for(int k=0; k<j; k++)
                ok = ok && T[i+k] == j;
            if (ok)
                A[j].insert(i);
        }
    }
    
    int n, k;
    while(cin >> n >> k) {
        set<int>::iterator limit = A[k].upper_bound(n);
        set<int>::iterator it = A[k].begin();
        for(; it != limit; it++) {
            cout << *it << endl;
        }

    }
    

}

