#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int mod = 2019;
int main() {
    long l,r;
    cin >> l >> r;
    // r = min(r, l+2019);

    // int mmin = 2018;
    // for(int i=l; i<=r; i++) {
    //     for (int j=i+1; j<=r; j++) {
    //         mmin = min(mmin, (i*j)%mod);
    //     }
    // }

    if ( r - l >= mod ) {
        puts("0");
        return 0;   
    }
    r%=mod;
    l%=mod;

    int mmin = 2018;
    for(int i=l; i<=r; i++) {
        for (int j=i+1; j<=r; j++) {
            mmin = min(mmin, (i*j)%mod);
        }
    }
    cout << mmin << endl;
}

/*
L = 2020
R = 4040

if( (R - L) >= 2019 ) {
    puts("0");
    return 0;
}

i = (2019 * n) 
j は適当な数字

(2019 * n) * j (mod 2019) ≡ 0

ans : 0
*/