#include <iostream>
#include <algorithm>
#define ull unsigned long long
using namespace std;

int T[10], P[] = {2, 3, 5, 7, 11, 13, 17};


int main() {
    int n;
    while(cin >> n) {
        for(int i=0; i<=n; i++)
            T[i] = i;

        ull total = 0;
        while(next_permutation(T, T+n+1)) {
            bool ok = true;
            for(int i=1;i<=n-2 and ok; i++) {
                int test = T[i]*100+T[i+1]*10+T[i+2];
                ok = ok && test%P[i-1] == 0;
            }
            if (ok) {
                ull sum = 0;
                for(int i=0; i<=n; i++)
                    sum = sum*10+T[i];
                total += sum;
            }
        }
        cout << total << endl;
    }

}

