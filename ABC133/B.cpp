#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> x[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            
            long double sum = 0;
            for (int k = 0; k < d; ++k) {
                sum += pow(x[i][k] - x[j][k], 2.0);
            }
            sum = sqrt(sum);
            if (sum == (int)sum)
                ans++;
        }
    }
    cout << ans << endl;
}

/*  N=3  D=2
0 →    1 2
1 →    5 5
2     -2 8

0 1
√ |1-5|^2 + |2-5|^2

0 1
0 2
1 2
 */
