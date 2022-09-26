#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<int>adj[], vector<int>&vis, int node) {
    for (auto curr : adj[node]) {
        if (vis[curr] == -1) {
            vis[curr] = !vis[node];
            if (!isBipartite(adj, vis, curr))
                return false;
        }
        else if (vis[curr] == vis[node]) {
            return false;
        }
    }
    return true;
}

 int main() {
    int n, m;
    cin >> n >> m;
    vector<int>adj[n+1];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int>vis(n+1, -1);
    bool possible = true;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == -1) {
            vis[i] = 1;
            if (!isBipartite(adj, vis, i)) {
                possible = false;
                break;
            }
        }
    }
    if (!possible) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (int i = 1; i <= n; i++)
            cout << vis[i]+1 << " ";
        cout << endl;
    }
    
    return 0;
}