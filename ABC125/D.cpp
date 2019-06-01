#include<iostream>
#include<vector>

using namespace std;

long long dp[100002][4];

void print_dp(long long n, long long k){
    for (long long i=0; i<k; i++){
        for (long long j=1; j<n; j++) {
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main (void) {
    long long n;
    long long a1, a2;

    cin >> n;

    cin >> a1;
    cin >> a2;
    dp[1][0] = a1 + a2;
    dp[1][1] = -(a1 + a2);
    for (long long i=2; i<n; i++) {
        a1 = a2;
        cin >> a2;

        dp[i][0] = max(dp[i-1][0] + a2, dp[i-1][1] + a2);
        dp[i][1] = max(dp[i-1][0] + -2*a1 + -a2, dp[i-1][1] + 2*a1 + -a2);
        // print_dp(n,2);
    }


    cout << max(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}
