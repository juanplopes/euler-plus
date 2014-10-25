#include <iostream>
#define ull unsigned long long
using namespace std;

int D[100001];
int N[100001];

int d(int i) {
    if (i<0 or i>=100000) return -1;
    return D[i];
}

int main() {
    for(int i=1; i<50000; i++) {
        for(int j=i*2; j<100000; j+=i)
            D[j] += i;
    }

    for(int a=1; a<=100000; a++) {
        N[a] = N[a-1];
        int b = d(a);
        if (a==d(b) and a!=b)
            N[a] += a;
    }

    int cases, n; cin >> cases;
    while(cin >> n)
        cout << N[n] << endl;
}
