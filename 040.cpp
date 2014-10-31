#include <iostream>
#define ull long long
using namespace std;

ull P10[19], S[19], L[19];


int D(ull n) {
    n--;
    ull x, d, f;
    for(int i=0; i<19; i++) {
        if (n-L[i]<0) {
            x = (n+S[i])/(i+1);
            d = (n+S[i])%(i+1);
            f = i;
            break;
        }
        n -= L[i];  
    }
    return (x/P10[f-d])%10;
}

int main() {
    P10[0] = 1; S[0] = 1; L[0] = 9;
    for(int i=1; i<19; i++)
        L[i] = (S[i] = (P10[i] = P10[i-1]*10) * (i+1)) * 9;

    int cases; cin >> cases;
    ull a, b, c, d, e, f, g;
    while(cin >> a >> b >> c >> d >> e >> f >> g) {
        cout << D(a) * D(b) * D(c) * D(d) * D(e) * D(f) * D(g) << endl;
    }

}

