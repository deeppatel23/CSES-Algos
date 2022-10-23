#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
// long long int solve(vector<int>nums, int m, int idx) {
//     if (idx == nums.size()) {
//         return 1;
//     }
//     if (nums[idx] != 0) {
//         return solve(nums, m, idx+1);
//     }
//     int ans = 0;
//     for (int i = 1; i <= m; i++) {
//         if (idx == 0 && nums[idx+1] != 0 && abs(i-nums[idx+1]) <= 1) {
//             nums[idx] = i;
//             ans = (ans + solve(nums, m, idx+1)) % mod;
//         }
//         else if (idx == 0 && nums[idx+1] == 0) {
//             nums[idx] = i;
//             ans = (ans + solve(nums, m, idx+1)) % mod;
//         }
//         else if (idx == nums.size()-1 && abs(i-nums[idx-1]) <= 1) {
//             nums[idx] = i;
//             ans = (ans + solve(nums, m, idx+1)) % mod;
//         }
//         else if (nums[idx+1] != 0 && abs(i-nums[idx-1]) <= 1 && abs(i - nums[idx+1]) <= 1) {
//             nums[idx] = i;
//             ans = (ans + solve(nums, m, idx+1)) % mod;
//         }
//         else if (abs(i-nums[idx-1]) <= 1 && nums[idx+1] == 0) {
//             nums[idx] = i;
//             ans = (ans + solve(nums, m, idx+1)) % mod;
//         }
//         // cout << nums[idx] << ":" << idx << " ";
//     }
//     return ans;
// }

int solve(vector<int>nums, int m, int idx) {
    int n = nums.size();
    int dp[n+2][m+2];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1) {
                if (nums[i-1] == 0 || nums[i-1] == j) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = 0;
                }
            }
            else {
                if (nums[i-1] == 0 || nums[i-1] == j) {
                    dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j])%mod + dp[i-1][j+1])%mod;
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
    }
    int ans = 0;
    for(int x = 1; x <= m; x++)
        ans = (ans + dp[n][x]) % mod;
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int>nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    bool validIp = true;
    for (int i = 1; i < n; i++) {
        if (nums[i-1] != 0 && nums[i] != 0 && abs(nums[i-1] - nums[i]) > 1) {
            validIp = false;
        }
    }
    if (!validIp) 
        cout << 0 << endl;
    else if (n == 1 && nums[0] == 0)
        cout << m << endl;
    else if (n == 1)
        cout << 1 << endl;
    else
        cout << solve(nums, m, 0) << endl;
    return 0;
}