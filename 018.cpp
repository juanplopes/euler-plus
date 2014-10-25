#include <iostream>
#define ull unsigned long long
using namespace std;

ull T[16][16];

int main() {
    int cases, n; cin >> cases;
    while(cin >> n) {
        for(int i=0; i<n; i++)
            for(int j=0; j<i+1; j++)
                cin >> T[i][j];

        for(int i=n-2; i>=0; i--)
            for(int j=0; j<i+1; j++)
                T[i][j] = max(T[i][j]+T[i+1][j+1], T[i][j]+T[i+1][j]);
        cout << T[0][0] << endl;
    }
}
