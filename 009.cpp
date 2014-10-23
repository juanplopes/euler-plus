#include <iostream>
#include <cmath>
#define ull unsigned long long
using namespace std;


int main() {
    int cases, n; cin >> cases; 
    while(cin >> n) {
        int maxx = -1;
        for(int a=0; a<=n; a++) {
            double b = (n*n - 2*n*a) / (2*n - 2.0*a);
            double c = sqrt(a*a+b*b);
            if (b==(int)b and c==(int)c and a<b and b<c)
                maxx = max(maxx, (int)(a*b*c));
        }
        cout << maxx << endl;
    }
}
