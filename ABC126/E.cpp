#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define ASIZE 100010

void dfs(const int& i, vector<int> (&ad)[ASIZE], vector<bool>& visited) {
    if ( visited[i] ) return;
    visited[i] = true;
    for (auto v : ad[i] ) {
        dfs(v, ad, visited);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < int > ad [ASIZE];
    vector <bool> visited (ASIZE, false);
    int ans = 0;

    for (int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ad[x].push_back(y);
        ad[y].push_back(x);
    }
    

    for (int i=1; i<=n; i++) {
        if ( visited[i] ) continue;
        ans++;
        dfs(i, ad, visited);
    }

    cout << ans << endl;
}