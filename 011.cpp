#include <iostream>
using namespace std;

int T[30][30];

int main() {
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            cin >> T[i][j];
   
    int maxx = 0;
    for(int i=0; i<20; i++)
    for(int j=0; j<20; j++) {
        int s=1, e=1, se=1, ne=1;
        for(int k=0; k<4; k++) {
            if (i+3<20)
                s *= T[i+k][j];
            if (j+3<20)
                e *= T[i][j+k];
            if (i+3<20 and j+3<20)
                se *= T[i+k][j+k];
            if (i-3>=0 and j+3<20)
                ne *= T[i-k][j+k];
        }
        if (i+3<20)
            maxx = max(maxx, s);
        if (j+3<20)
            maxx = max(maxx, e);
        if (i+3<20 and j+3<20)
            maxx = max(maxx, se);
        if (i-3>=0 and j+3<20)
            maxx = max(maxx, ne);
            
    }
    cout << maxx << endl;


}
