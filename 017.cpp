#include <iostream>
#include <map>
#include <string>
#define ull unsigned long long
using namespace std;

string U[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string D[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string T[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string M[] = {"", "Thousand", "Million", "Billion", "Trillion"};


string up100(int n) {
    if (n<10)  return U[n];
    if (n==10) return D[1];
    if (n<20) return T[n-10];
    if (n%10==0) return D[n/10];
    return D[n/10] + " " + U[n%10];
}

string up1000(int n) {
    if (n<100) return up100(n);
    if (n%100==0) return U[n/100] + " Hundred";
    return U[n/100] + " Hundred " + up100(n%100);
}

string full(ull n) {
    if (not n) return "Zero";
    string answer = "";
    for(int i=0; i<=4 && n; i++) {
        if (n%1000) {
            answer = up1000(n%1000) + 
                     (i>0?" "+M[i]:"") + 
                     (answer != "" ? " ":"") + 
                     answer;
        }
        n/=1000;
    }
    return answer;
}

int main() {
    int cases; cin >> cases;
    ull n;
    while(cin >> n)
        cout << full(n) << endl;
}
