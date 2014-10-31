#include <iostream>
#include <cmath>
#define ull long long
using namespace std;

bool is_pent(ull n) {
    double x = (sqrt(0.25+6*n)+0.5)/3;
    return abs(x-round(x)) < 1e-8;
}

ull pent(ull n) {
    return n*(3*n-1)/2;
}

int main() {
    int n, k;
    while(cin >> n >> k) {
        for(int i=k; i<n; i++) {
            if (is_pent(pent(i+1)-pent(i+1-k)) or is_pent(pent(i+1)+pent(i+1-k)))
                cout << pent(i+1) << endl;
        }
    }

}

