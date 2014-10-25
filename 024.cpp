#include <iostream>
#define LIMIT 100100
#define ull unsigned long long
using namespace std;

int T[13];

void kth_permutation(int n, ull k) {
    for(int j=1; j<=n; j++) {
        T[n-j] = (k % j);
        k /= j;
    }

    T[n-1] = 0;
    for(int i=n-2; i>=0; i--)
        for(int j=i+1; j<n; j++)
            if(T[j] >= T[i])
                T[j] += 1;
}

int main() {
    int cases; cin >> cases;
    ull n;
    while(cin >> n) {
        kth_permutation(13, n-1);
        for(int i=0; i<13; i++)
            cout << (char)(T[i]+'a');
        cout << endl;
    }
}
