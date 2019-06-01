#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long m, k;
    cin >> m >> k;
    
    long max = pow(2, m);

    if (m == 1) {
        if (k == 0)
            cout << "0 0 1 1" << endl;
        else
            cout << -1 << endl;
        return 0;
    }

    if (k >= max) {
        cout << -1 << endl;
        return 0;
    }
    
    cout << k;
    for (long i=0; i<max; i++) {
        if (i == k) continue;
        cout << " " << i;
    }
    cout << " " << k;
    for (long i=max-1; i>=0; i--) {
        if (i == k) continue;
        cout << " " << i;
    }
    cout << endl;
}