#include<bits/stdc++.h>
using namespace std;

int mod;
int dp[1000001][6];
int solve(vector<int>&dice, int idx, int req) {
    if (req == 0) {
        return 1;
    }
    if (req < 0 || idx == dice.size()) {
        return 0;
    }
    if (dp[req][idx] != -1)
        return dp[req][idx];
    int c1 = 0, c2 = 0;
    if (req-dice[idx] >= 0) {
        c1 = solve(dice, 0, req-dice[idx]);
    }
    c2 = solve(dice, idx+1, req);
    return dp[req][idx] = (c1%mod + c2%mod)%mod;
}

int main() {
    int sum;
    cin >> sum;
    mod = 1e9 + 7;
    memset(dp, -1, sizeof(dp));
    vector<int> dice;
    for (int i = 1; i <= 6; i++) {
        dice.push_back(i);
    }
    cout << solve(dice, 0, sum);
    return 0;
}