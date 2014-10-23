#include <iostream>
#define ull unsigned long long
using namespace std;

int main() {
    int cases, n; cin >> cases; 
    while(cin >> n) {
        ull a=0, b=0;
        for(ull i=1; i<=n; i++) {
            a+=i;
            b+=i*i;
        }
        cout << a*a-b << endl;
    }
}

