#include<bits/stdc++.h>
using namespace std;

//TLE
int mod;
int dp[1000001][101];
// int solve(vector<int>&coins, int idx, int req) {
//     if (req == 0) {
//         return 0;
//     }
//     if (idx == coins.size()) {
//         return 1e6+1;
//     }
//     if (dp[req][idx] != -1) {
//         return dp[req][idx];
//     }
//     if (req - coins[idx] < 0) {
//         return 1e6+1;   //coins is sorted and now no further answer possible with big value coins
//     }
//     int c1 = 1e6+1, c2 = 1e6+1;
//     if (req - coins[idx] >= 0) {
//         c1 = 1 + solve(coins, idx, req-coins[idx]);
//     }
//     c2 = solve(coins, idx+1, req);
//     return dp[req][idx] = min(c1, c2);
// }

int solve(vector<int>coins, int idx, int x) {
    int n = coins.size();
    vector<int> dp2(x+1,1e9);
    dp2[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i-coins[j] >= 0) {
                dp2[i] = min(dp2[i], dp2[i-coins[j]]+1);
            }
        }
    }
    return dp2[x] == 1e9 ? -1 : dp2[x]; 
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int>coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    sort(coins.begin(), coins.end());
    memset(dp, -1, sizeof(dp));
    mod = 1e9+7;
    int ans = solve(coins, 0, x);
    ans == INT_MAX ? cout << -1 : cout << ans;
    return 0;
}