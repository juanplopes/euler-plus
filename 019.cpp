#include <iostream>
#define ull unsigned long long
using namespace std;

int MD[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};



int main() {
    int cases; cin >> cases;
    ull y1, m1, d1, y2, m2, d2;
    while(cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2) {
        int leap = y1%4==0 and (y1%100 != 0 or y1%400 == 0) ? 1 : 0;

        ull day = (y1-1900)%7*365+((y1-1)/4-(y1-1)/100+(y1-1)/400)-460;
        for(int i=1; i<m1; i++)
            day += MD[leap][i];
        day += (d1-1);
        day %= 7;

        ull result = 0;
        while(y1!=y2 || m1!=m2 || d1!=d2) {
            if (d1==1 and day==6)
                result++;
            d1++;
            day=(day+1)%7;
            if (d1 > MD[leap][m1]) {
                d1 = 1;
                m1++;
            }
            
            if (m1 > 12) {
                m1 = 1;
                y1++;
                leap = y1%4==0 and (y1%100 != 0 or y1%400 == 0) ? 1 : 0;
            }
        }
        if (d1==1 and day==6)
            result++;

        cout << result << endl;
   }
}
