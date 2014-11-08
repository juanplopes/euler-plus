#include <iostream>
#include <cstring>
#define LIM 1010
#define ull long long
using namespace std;

ull C[LIM][LIM];

int main() {
    int n; ull k;
    while(cin >> n >> k) {
        for(int i=0; i<=n; i++)
            C[i][0] = C[0][i] = C[i][i] = 1;

        int answer = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<i; j++) {
                if (C[i-1][j-1] > 0 and C[i-1][j] > 0) {
                    C[i][j] = C[i-1][j-1] + C[i-1][j];
                    if (C[i][j] > k or C[i][j] <= 0) {
                        C[i][j] = -1;
                        answer++;
                    }
                } else {
                    C[i][j] = -1;
                    answer++;
                }
            }
        }
        cout << answer << endl;
       
    }

}

