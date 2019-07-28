#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <utility>
#include <sstream>
#include <numeric>
#include <iterator>

using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repd(i,0,n)

typedef long long ll;
typedef pair<int, int> P;



int main(int argc, const char * argv[]) {

	const int mod = 1000000007;
	string s;
	cin >> s;
	int str_size = s.size();
	reverse(s.begin(), s.end());
	vector< vector<long> > dp(str_size+1, vector<long> (13,0));
    int digit = 1;
    dp[0][0] = 1;
	rep(i, str_size){
		if (s[i] == '?'){
			rep(j,10){
				rep(k, 13){
					dp[i+1][(j * digit + k) % 13 ] += dp[i][k];

				}
			}
		}else{
			rep(k, 13){
				dp[i+1][( (s[i]- '0') * digit + k) % 13 ] += dp[i][k];
			}
		}
		rep(j, 13) dp[i+1][j] %= mod;
		
        digit *=10;
        digit %=13;
	}


	cout << dp[str_size][5] << endl;
  
  
	return 0;
}
