#include <iostream>
#include <string>
#include <algorithm>
#define ull unsigned long long
using namespace std;

string S[6000];

int main() {
    int n, q;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> S[i];
    sort(S, S+n); 
   
    cin >> q;
    for(int i=0; i<q; i++) {
        string name; cin >> name;
        int pos = (int)(lower_bound(S, S+n, name)-S)+1;
        int sum = 0;
        for(int j=0; j<name.size(); j++)
            sum += name[j] - 'A' + 1;

        cout << sum*pos << endl;
    }
}
