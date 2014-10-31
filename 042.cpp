#include <iostream>
#include <cmath>
#define ull long long
using namespace std;

ull tri(ull n) {
    double x = (sqrt(1+8*n)-1)/2;
    if (abs(x-round(x)) > 1e-8) return -1;
    return (ull)x;
}

int main() {
    int cases; cin >> cases;
    ull n;
    while(cin >> n) {
        cout << tri(n) << endl;
    }

}

