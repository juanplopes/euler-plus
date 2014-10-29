#include <iostream>
#include <cstring>
using namespace std;

int D[10];

int pandigital(int a, int b, int c, int n) {
    memset(D, 0, sizeof(D));
    while(a) { D[a%10]++; a/=10; }
    while(b) { D[b%10]++; b/=10; }
    while(c) { D[c%10]++; c/=10; }
    for(int i=0; i<10; i++)
        if (D[i] != (i>=1 and i<=n ? 1 : 0)) 
            return false;
    return true;
}

bool P[10000];

int main() {
    int n;
    while(cin >> n) {
        int total = 0;
        memset(P, 0, sizeof P);
        for(int i=1; i<10000; i++) {
            for(int j=i; j<10000; j++) {
                if (i*j < 10000 and not P[i*j] and pandigital(i, j, i*j, n)) {
                    P[i*j] = true;
                    total += i*j;
                }
            }
        }        
        cout << total << endl;
    }

}

