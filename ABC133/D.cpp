#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repd(i,0,n)

int main() {

    int n;
    cin >> n;
    vector <long> a(n); 
    vector <long> x (n,0);

    rep(i,n){
        cin >> a[i];
        if (i%2==0) {
            x[0] += a[i];
        } else {
            x[0] -= a[i];
        }
    }

    cout << x[0] << " ";
    rep(i,n-1) {
        x[i+1] = 2*a[i] - x[i];
        cout << x[i+1] << " ";
    }
    cout << endl;


}

/*
  x1 + x2  =  2 * A1
  x2 + x3  =  2 * A2
  x3 + x4  =  2 * A3
  x4 + x5  =  2 * A4
  x5 + x1  =  2 * A5

    x1 + x2      = 2*A1
         x2 + x3 = 2*A2
  - 
------------------------
    x1 - x3 = 2*A1 - 2*A2

  2 * x1 = hogehoge
 */