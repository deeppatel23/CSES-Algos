#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int mod;
// int dp[1000001][101];
// int solve(vector<int>&coins, int idx, int req) {
//     if (req == 0) {
//         return 1;
//     }
//     if (req < 0 || idx == coins.size()) {
//         return 0;
//     }
//     if (dp[req][idx] != -1) {
//         return dp[req][idx];
//     }
//     if (req-coins[idx] < 0) {
//         return 0;
//     }
//     int c1 = 0, c2 = 0;
//     if (req-coins[idx] >= 0) {
//         c1 = solve(coins, idx, req-coins[idx]);
//     }
//     c2 = solve(coins, idx+1, req);
//     return dp[req][idx] = (c1%mod + c2%mod)%mod;
// }

// int main() {
//     int n, sum;
//     cin >> n >> sum;
//     mod = 1e9 + 7;
//     memset(dp, -1, sizeof(dp));
//     vector<int> coins(n);
//     for (int i = 0; i < n; i++) {
//         cin >> coins[i];
//     }
//     sort(coins.begin(), coins.end());
//     cout << solve(coins, 0, sum) << endl;
//     return 0;
// }

int main(){
    int n, sum;
    cin >> n >> sum;
    mod = 1e9 + 7;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
	vector<int>dp2(sum+1, 0);
    dp2[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int weight = 0; weight <= sum; weight++) {
			if(weight - coins[i - 1] >= 0) {  // prevent out of bounds cases
				dp2[weight] += dp2[weight - coins[i - 1]];
				dp2[weight] %= mod;
			}
		}
	}
	cout << dp2[sum] << '\n';
}