#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//TLE
// unordered_map<string, int>u;
// int solve(string s, int idx) {
//     if (idx == s.size()) {
//         return 1;
//     }
//     string temp;
//     int ans = 0;
//     for (int i = idx; i < s.size(); i++) {
//         temp += s[i];
//         if (u[temp] > 0) {
//             ans += solve(s, i+1);
//         }
//     }
//     return ans;
// }

int main() {
    string word;
    cin >> word;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        u[s]++; 
    }
    // cout << solve(word, 0) << endl;

    return 0;
}