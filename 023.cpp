#include <iostream>
#define LIMIT 100100
#define ull unsigned long long
using namespace std;

int F[LIMIT];
int T[LIMIT];

int main() {
    for(int i=1;i<LIMIT/2; i++)
        for(int j=i*2; j<LIMIT; j+=i)
            F[j] += i;

    int abundant = 0;
    for(int i=0; i<LIMIT; i++)
        if (F[i]>i)
            T[abundant++] = i;

    int cases, n; cin >> cases;
    while(cin >> n) {
        bool answer = false;
        for(int i=0; i<abundant and T[i]<=n/2; i++) {
            int rem = n-T[i];
            if (F[rem] > rem) {
                answer = true;
                break;
            }
        }
        cout << (answer ? "YES" : "NO") << endl;
        
    }
}
