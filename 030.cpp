#include <iostream>
#include <cmath>
#define ull unsigned long long
using namespace std;

int D[10];

bool ok(int n) {
    int sum = 0, temp = n;
    while(temp) {
        sum += D[temp%10];
        temp/=10;
    }
    return sum == n;
       
}

int main() {
    int n;
    while(cin >> n) {
        for(int i=0; i<10; i++)
            D[i] = (int)pow(i, n);
        
        int total = 0;
        for(int i=2; i<1000000; i++)
            if (ok(i))
                total += i;
        
        cout << total << endl;
    }

}

