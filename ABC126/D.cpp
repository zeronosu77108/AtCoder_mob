#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>


using namespace std;

#define ASIZE 100010

void dfs(const long& i, const long& start, const long& rootW,  const long& n, vector< pair<long,long> > (&ad)[ASIZE], vector<bool>& visited, vector<bool>& ans) {
    if ( visited[i] ) return;
    visited[i] = true;
    ans[i] = rootW%2==0 ? ans[start] : !ans[start];

    for (auto v : ad[i] ) {
        dfs(v.first, start, rootW + v.second, n, ad, visited, ans);
    }
}

int main() {
    long n;
    cin >> n;
    vector < pair<long,long> > ad [ASIZE];
    vector <bool> visited (ASIZE, false);
    vector <bool> ans (ASIZE, false);

    for (long i=1; i<n; i++) {
        long u,v,w;
        cin >> u >> v >> w;
        // ad[u][v] = ad[v][u] = w;
        ad[u].push_back( make_pair(v,w) );
        ad[v].push_back( make_pair(u,w) );
    }
    

    for (long i=1; i<=n; i++) {
        if ( visited[i] ) continue;
        ans[i] = true;
        dfs(i, i, 0, n, ad, visited, ans);
    }

    for (long i=1; i<=n; i++) {
        cout << ans[i] << endl;
    }
    // cout << endl;
  
}