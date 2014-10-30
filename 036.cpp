#include <iostream>
using namespace std;

bool pal(int n, int k) {
    int d = n;
    int sum = 0;
    while(d) {
        sum = sum*k + d%k;
        d/=k;
    }
    return n==sum;
}

int main() {
    int n, k;
    while(cin >> n >> k) {
        int total = 0;
        for(int i=1; i<n; i++) {
            if (pal(i, 10) and pal(i, k))
                total += i;
        }
        cout << total << endl;
    }

}

