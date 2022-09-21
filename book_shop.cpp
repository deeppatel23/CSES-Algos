#include<bits/stdc++.h>
using namespace std;

// int dp[100001][1001];
// int solve(vector<int>&prices, vector<int>&pages, int idx, int x) {
//     if (idx == prices.size()) {
//         return 0;
//     }
//     if (dp[x][idx] != -1) {
//         return dp[x][idx];
//     }
//     int c1 = 0, c2 = 0;
//     if (x - prices[idx] >= 0) {
//         c1 = pages[idx] + solve(prices, pages, idx+1, x - prices[idx]);
//     }
//     c2 = solve(prices, pages, idx+1, x);
//     return dp[x][idx] = max(c1, c2);
// }

int main() {
    int n, x;
    cin >> n >> x;
    vector<int>prices(n), pages(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    // memset(dp, -1, sizeof(dp));
    // cout << solve(prices, pages, 0, x) << endl;

    vector<vector<int> >dp(n+1, vector<int>(x+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j]; //book not included so total price(j) remains same
            int remainingMoney = j - prices[i-1];
            if (remainingMoney >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][remainingMoney] + pages[i-1]);
            }
        }
    }
    cout << dp[n][x] << endl; 

    return 0;
}