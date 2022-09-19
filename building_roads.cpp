#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[], vector<bool>&vis, int idx) {
    vis[idx] = true;
    for (auto neg : adj[idx]) {
        if (!vis[neg]) {
            dfs(adj, vis, neg);
        }
    }
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

    int count = 0;
    vector<pair<int, int> >v;
    vector<bool>vis(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(adj, vis, i);
            if (i != 1) {
                v.push_back(make_pair(i-1, i));
                count++;
            }
        }
    }
    cout << count << endl;
    for (int i = 0; i < count; i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}