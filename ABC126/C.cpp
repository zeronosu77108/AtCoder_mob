#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long n,k;
    long double ans;
    ans = 0.0;
    cin >> n >> k;
    for (long long i=1; i<=n; i++) {
        long double tmp = 1.0/n;
        int sum = i;
        while( sum < k ) {
            sum *=2.0;
            tmp /=2.0;
        }
        ans += tmp;
    }
    // cout << ans << endl;
    printf("%.12Lf\n", ans);
}