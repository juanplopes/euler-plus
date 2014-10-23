#include <iostream>
#include <string>
using namespace std;

int N[100];
int size=0;

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        
        int carry = 0;
        for(int i=0; i<s.size() or carry; i++) {
            N[i] += (i<s.size() ? s[s.size()-i-1]-'0' : 0) + carry;
            carry = N[i]/10;
            N[i] %= 10;
            if (N[i])
                size = max(size, i);
        }
    }

    size = max(size, 9);
    for(int i=size; i>=size-9; i--)
        cout << N[i];
    cout << endl;


}
