#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int,int);

int main (void) {
    int n;
    int a[100002];
    int left[100002], right[100002];

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    left[0] = a[0];
    right[n-1] = a[n-1];
    for (int i=1; i<n; i++) {
        left[i] = gcd(left[i-1], a[i]);
        right[n-i-1] = gcd(right[n-i], a[n-i-1]);
    } 

    // right[n-1] = a[n-1];
    // for (int i=n-2; i>=0; i--) {
    //     right[i] = gcd(right[i+1], a[i]);
    // }

    int ans = max(left[n-2], right[1]);
    for (int i=1; i<n-1; i++) {
        ans = max(ans, gcd(left[i-1],right[i+1]));
    }

    cout << ans << endl;

}

int gcd(int a, int b) { 
    if (b>a) {
        int t = b;
        b = a;
        b = t;
    }
    int m = a%b;

    if (m == 0) {
        return b; 
    }
    return gcd(b, m); 
} 