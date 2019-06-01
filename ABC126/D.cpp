#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>


using namespace std;

#define ASIZE 100010

void dfs(const int& i, const int& start, const int& rootW,  const int& n, vector< pair<int,bool> > (&ad)[ASIZE], vector<bool>& visited, vector<bool>& ans) {
    if ( visited[i] ) return;
    visited[i] = true;
    ans[i] = rootW%2==0 ? ans[start] : !ans[start];

    for (auto v : ad[i] ) {
        dfs(v.first, start, rootW + v.second, n, ad, visited, ans);
    }
}

int main() {
    int n;
    cin >> n;
    vector < pair<int,bool> > ad [ASIZE];
    vector <bool> visited (ASIZE, false);
    vector <bool> ans (ASIZE, false);

    for (int i=1; i<n; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        // ad[u][v] = ad[v][u] = w;
        ad[u].push_back( make_pair(v,w%2) );
        ad[v].push_back( make_pair(u,w%2) );
    }
    

    for (int i=1; i<=n; i++) {
        if ( visited[i] ) continue;
        ans[i] = true;
        dfs(i, i, 0, n, ad, visited, ans);
    }

    for (int i=1; i<=n; i++) {
        cout << ans[i] << endl;
    }
    // cout << endl;
  
}