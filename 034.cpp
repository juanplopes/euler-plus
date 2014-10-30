#include <iostream>
using namespace std;

int F[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int fsum(int n) {
    int sum = 0;
    while(n) {
        sum += F[n%10];
        n/=10;
    }
    return sum;
}

int main() {
    int n;
    while(cin >> n) {
        int total = 0;
        for(int i=10; i<n; i++)
            if (fsum(i)%i == 0) { total += i; }
        cout << total << endl;
    }

}

