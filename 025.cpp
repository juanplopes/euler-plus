#include <iostream>
#include <cmath>
#define PHI 1.618033988749894848
using namespace std;

int main() {
    int cases, n; cin >> cases;
    while(cin >> n) {
        cout << ceil(((n-1) * log(10.0) + log(5.0) / 2) / log(PHI)) << endl;
    }
}
