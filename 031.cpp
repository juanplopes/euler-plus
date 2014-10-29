#include <iostream>
using namespace std;

int W[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int T[100100][8];

int main() {
    for(int j=0; j<8; j++)
        T[0][j] = 1;

    for(int i=1; i<=100000; i++) {
        for(int j=0; j<8; j++) {
            if (i-W[j] >= 0) 
                T[i][j] = (T[i][j] + T[i - W[j]][j]) % 1000000007;

            if (j-1>=0)      
                T[i][j] = (T[i][j] + T[i][j-1]) % 1000000007;
        }
    }

    int n, cases; cin >> cases;
    while(cin >> n) {
        cout << T[n][7] << endl;
    }

}

