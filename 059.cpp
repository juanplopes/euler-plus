#include <iostream>
using namespace std;

char N[3], M[3];
int T[1510], n;

int score() {
    int score = 0;
    for(int i=0; i<n; i++) {
        int x = T[i] ^ N[i%3];
        if (x<32 or x>122) return 0;
        if (x>='a' and x<='z' or x>='A' and x<='Z') score++;
    }
    return score; 
}

int main() {
    while(cin >> n) {
        for(int i=0; i<n; i++)
            cin >> T[i];

        int maxx = 0;    
        for(N[0]='a'; N[0]<='z'; N[0]++)
        for(N[1]='a'; N[1]<='z'; N[1]++)
        for(N[2]='a'; N[2]<='z'; N[2]++) {
            int value = score();
            if (value > maxx) {
                M[0] = N[0];
                M[1] = N[1];
                M[2] = N[2];
                maxx = value;
            }
        }

        cout << M[0] << M[1] << M[2] << endl;
    }
}
