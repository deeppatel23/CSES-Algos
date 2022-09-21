#include<bits/stdc++.h>
using namespace std;

int mod;
int dp[1001][1001];
int solve (vector<vector<char> >&path, vector<vector<bool> >&vis, int i, int j) {
    int n = path.size();
    if (i < 0 || j < 0 || i >= n || j >= n || path[i][j] == '*' || vis[i][j]) {
        return 0;
    }
    if (i == n-1 && j == n-1) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    vis[i][j] = true;
    int right = solve(path, vis, i, j+1);
    int down = solve(path, vis, i+1, j);
    vis[i][j] = false;
    return dp[i][j] = (right%mod + down%mod) % mod;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char> >path(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> path[i][j];
        }
    }
    mod = 1e9 + 7;
    memset(dp, -1, sizeof(dp));
    vector<vector<bool> >vis(n, vector<bool>(n, false));
    cout << solve(path, vis, 0, 0) << endl;
    return 0;
}