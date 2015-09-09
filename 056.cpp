#include <iostream>
#include <cstring>
#define LIM 101000
#define LIM2 200
using namespace std;

int TEMP[LIM], K[LIM2];
int tsize = 0;

int main() {
    for(int a=2; a<LIM2; a++) {
        memset(TEMP, 0, sizeof(TEMP));
        TEMP[0] = 1;

        for(int b=1; b<LIM2; b++) {
            int carry = 0;
            
            for(int i=0; i<=tsize or carry>0; i++) {
                TEMP[i] *= a;
                TEMP[i] += carry;
                carry = TEMP[i]/10;
                TEMP[i]%=10;
                tsize = max(tsize, i);
            }
            
            int sum = 0;
            for(int i=0; i<=tsize; i++) {
                sum += TEMP[i];
            }
            K[max(a,b)] = max(K[max(a,b)], sum);
        }
    }

    int n;
    while(cin >> n) {
        int maxx = 1;
        for(int i=0; i<n; i++) {
            maxx = max(maxx, K[i]);
        }
        cout << maxx << endl;
    }
}

