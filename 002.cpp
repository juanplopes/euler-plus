#include <iostream>
#define ull unsigned long long
using namespace std;

int main() {
    ull cases, n; cin >> cases;

    while(cin >> n) {
        ull a=2, b=1, c=1, sum=0;
        while(a<=n) {
            if (a%2==0)
                sum+=a;
            c=b;
            b=a;
            a=b+c;
        }
        
        cout << sum << endl;
    }
}
