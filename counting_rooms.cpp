#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char> >&g, int i, int j) {
    int n = g.size(), m = g[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || g[i][j] == '#') {
        return;
    }
    g[i][j] = '#';
    dfs(g, i+1, j);
    dfs(g, i-1, j);
    dfs(g, i, j+1);
    dfs(g, i, j-1);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> >grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                ans++;
                dfs(grid, i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}