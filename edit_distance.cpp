#include<bits/stdc++.h>
using namespace std;

// int dp[5001][5001];
// int solve(string a, string b, int ia, int ib) {
//     if (ia == a.size()) {
//         return b.size() - ib;
//     }
//     if (ib == b.size()) {
//         return a.size() - ia;
//     }
//     if (a[ia] == b[ib]) {
//         return solve(a, b, ia+1, ib+1);
//     }
//     if (dp[ia][ib] != -1) {
//         return dp[ia][ib];
//     }
//     int replace = 1 + solve(a, b, ia+1, ib+1);
//     int add = 1 + solve(a, b, ia+1, ib);
//     int remove = 1 + solve(a, b, ia, ib+1);
//     return dp[ia][ib] = min(min(replace, remove), add);
// }

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    // memset(dp, -1, sizeof(dp));
    // cout << solve(a, b, 0, 0) << endl;

    vector<vector<int> > dp(str1.size() + 1, vector<int>(str2.size() + 1, INT32_MAX));
	dp[0][0] = 0;
	for (int i = 0; i <= str1.size(); i++) {
		for (int j = 0; j <= str2.size(); j++) {
			if (i != 0) {
				// Delete letter i - 1 from the string.
				dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
			}
			if (j != 0) {
				// Add letter j - 1 of the result to the string.
				dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
			}

			// Make letter i - 1 equal to letter j - 1 of the result.
			if (i != 0 && j != 0) {
				int new_cost = dp[i - 1][j - 1] + (str1[i - 1] != str2[j - 1]);
				dp[i][j] = std::min(dp[i][j], new_cost);
			}
		}
	}
    cout << dp[str1.size()][str2.size()] << endl;
    return 0;
}