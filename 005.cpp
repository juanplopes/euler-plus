#include <iostream>
#define ull unsigned long long
using namespace std;

ull gcd(ull a, ull b) {
    while(b) {
        ull t=b; b=a%b;  a=t;
    }
    return a;
}

ull lcm(ull a, ull b) {
    return a/gcd(a,b)*b;
}

int main() {
    int cases, n; cin >> cases; 
    while(cin >> n) {
        ull answer = 1;
        for(int i=2; i<=n; i++)
            answer = lcm(answer, i);
        cout << answer << endl;
    }
}

