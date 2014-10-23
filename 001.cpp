#include <iostream>
#define ull unsigned long long
using namespace std;

ull T(ull n, ull k) {
    ull m = n/k;
    return m*(m+1)/2*k;
}

int main() {
    int t, n; cin >> t;
    while(cin >> n) {
        cout << T(n-1, 3)+T(n-1, 5)-T(n-1, 15) << endl;
    }
}
