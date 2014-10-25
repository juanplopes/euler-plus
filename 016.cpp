#include <iostream>
#define ull unsigned long long
using namespace std;

int T[20001];
int N[10000];
int size = 0;


int main() {
    T[0] = N[0] = 1;

    for(int i=1; i<=10000; i++) {
        int carry = 0;
        for(int j=0; j<=size or carry; j++) {
            T[j]=T[j]*2+carry;
            carry = T[j]/10;
            T[j] %= 10;
            size = max(size, j);
            N[i] += T[j];
        }
    }

    int cases, n; cin >> cases;
    while(cin >> n)
        cout << N[n] << endl;
}
