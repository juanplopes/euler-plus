#include <iostream>
#include <cstring>
using namespace std;

int D[10];

bool ok(int n, int k) {
    memset(D, 0, sizeof D);
    int digits = 0;
    for(int i=1; i<10, digits<k; i++) {
        int mult = n*i;
        while(mult) {
            D[mult%10]++;
            mult/=10;
            digits++;
        }
    }
    if (digits!=k) return false;
    for(int i=0; i<10; i++)
        if (D[i] != (i>=1 and i<=k ? 1 : 0)) 
            return false;
    return true;
}

int main() {
    int n, k;
    while(cin >> n >> k) {
        for(int i=2; i<n; i++) {
            if (ok(i, k))
                cout << i << endl;
        }
    }

}

