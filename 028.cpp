#include <iostream>
#define ull long long
#define MOD 1000000007
using namespace std;

ull T(ull n) {
    ull x=((n+1)/2)%MOD;
    return ((x*(2*x-1))%MOD*(2*x+1)%MOD*333333336)%MOD;
}

ull L(ull n) {
    ull x = ((n-1)/2)%MOD;
    return (x*(x+1))%MOD;
}

int main() {
    ull cases, n; cin >> cases;
    while(cin >> n) {
        cout << ((4*T(n) - 6*L(n))%MOD+MOD)%MOD - 3 << endl;
    }
}
