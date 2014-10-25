#include <iostream>
#define ull unsigned long long
using namespace std;

ull T[501][501];

int main() {
    for(int i=0; i<=500; i++)
        T[i][0] = T[0][i] = 1;
    
    for(int i=1; i<=500; i++)
        for(int j=1; j<=500; j++)
            T[i][j] = (T[i-1][j] + T[i][j-1]) % 1000000007;
    
    int cases, a, b; cin >> cases;
    while(cin >> a >> b)
        cout << T[a][b] << endl;
}
