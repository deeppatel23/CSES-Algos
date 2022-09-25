#include<bits/stdc++.h>
using namespace std;

// int solve(vector<pair<int, int> >&edges, vector<bool>used, int idx) {
//     if (idx == edges.size()) {
//         return 0;
//     }
//     int x = edges[idx].first, y = edges[idx].second;
//     if (used[x] || used[y]) {
//         return 0;
//     } 
//     int c1 = 0, c2 = 0;
//     used[x] = true;
//     used[y] = true;
//     c2 = 1 + solve(edges, used, idx+1);
//     used[x] = false;
//     used[y] = false;
//     c1 = solve(edges, used, idx+1);
//     return max(c1, c2);
// }

int ans;

void dfs(vector<int> edges[], vector<bool> &vis, int node, int par) {
    for (auto adj : edges[node]) {
        if (adj != par) {
            dfs(edges, vis, adj, node);
            if (!vis[node] && !vis[adj]) {
                ans++;
                vis[node] = true;
                vis[adj] = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    ans = 0;
    vector<int>adj[n+1];
    vector<bool>used(n+1, false);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(adj, used, 1, 0);

    cout << ans;

    cout << endl;
    return 0;
}