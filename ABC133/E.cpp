#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int mod = 1'000'000'007;
vector<long> fact;
vector<long> ifact;

int mpow(int x, int y) {
    if (y==0) return 1;
    long a = mpow(x,y>>1);
    (a*=a) %= mod;
    if(y&1) (a*=x) %= mod;
    //cout << "x " << x << "  y " << y << "  a " << a << endl;
    return a;
}

void init(int n) {
    fact[0] = 1;
    for(int i=1; i<=n; ++i) fact[i] = fact[i-1]*i %mod;
    ifact[n] = mpow(fact[n], mod-2) % mod;
    for(int i=n; i>0; --i) ifact[i-1] = ifact[i]*i % mod;
}

long nPr(int n, int r) {
	return fact[n] * ifact[n-r] % mod;
}


void dfs(long& ans, const int k, vector< vector <int> >& g, const int now, const int p){
    // cout << "now1 : " << now << "\t ans : " << ans << endl;
    if ( p != 0 && g[now].size() <= 1 ) return;
    if (p == 0) (ans *= nPr(k-1, g[now].size())) %= mod;
    else (ans *= nPr(k-2, g[now].size() - 1)) %= mod;
    // cout << "now2 : " << now << "\t ans : " << ans << endl;
	
	for(auto child: g[now]){
        if (child == p) continue;
        dfs(ans, k, g, child, now);
	}
}


int main() {
	int n, k;
	cin >> n >> k;
    --n;
	vector< vector<int> > g(n+5);
    fact = vector<long>(k+2);
    ifact = vector<long>(k+2);
    init(k);
    // cout << "init fin" << endl;

	for(int i=0; i<n; ++i) {
		int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // cout << "input fin" << endl;

    long ans = k;
    dfs(ans, k, g, 1, 0);
    // cout << "dfs fin" << endl;
    cout << ans << endl;
}