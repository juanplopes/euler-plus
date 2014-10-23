#include <iostream>
#define ull unsigned long long
using namespace std;


int main() {
    int cases, n, k; cin >> cases; 
    while(cin >> n >> k) {
        string s;
        cin >> s;
        int maxx = 0;
        for(int i=0; i<s.size()-k; i++) {
            int prod = 1;
            for(int j=0; j<k; j++)
                prod*=s[i+j]-'0';
            maxx = max(maxx, prod);
        }
        
        cout << maxx << endl;
    }
}

