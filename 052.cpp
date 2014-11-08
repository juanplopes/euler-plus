#include <iostream>
#include <cstring>
using namespace std;

int T[6][10];

bool ok(int n, int k) {
    memset(T, 0, sizeof T);
    for(int i=0; i<k; i++) {
        int x = n*(i+1);
        while(x) {
            T[i][x%10]++;
            x/=10;
        }
        if (i>0) {
            for(int j=0; j<10; j++) {
                if (T[i][j] != T[i-1][j])
                    return false;
            }
        }
    }
    return true;
}


int main() {
    int n, k;
    while(cin >> n >> k) {
        for(int i=1; i<=n; i++) {
            if (ok(i, k)) {
                for(int j=0; j<k; j++)
                    cout << (j>0?" ":"") << i*(j+1);
                cout << endl;
            }
        }
        
    }

}

