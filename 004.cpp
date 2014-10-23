#include <iostream>
#include <set>
using namespace std;

bool ok(int n) {
    int a = 0, b = n;
    while(n>0) {
        a = a*10+n%10;
        n/=10;
    }
    return a==b;
}

set<int> T;

int main() {
    for(int a=100; a<1000; a++)
        for(int b=100; b<1000; b++)
            if (T.find(a*b)==T.end() and ok(a*b))
                T.insert(a*b);

    int cases, n; cin >> cases; 
    while(cin >> n) {
        set<int>::iterator it = T.lower_bound(n);
        it--;
        cout << *it << endl;
    }
}
