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

int trie[1000001][26];
bool stop[1000001];
int dp[5001];
int cnt = 0;
int mod = 1e9 + 7;

void insert(string s) {
    int node = 0;
    for (int i = 0; i < s.size(); i++) {
        if (trie[node][s[i] - 'a'] == 0) {
            trie[node][s[i] - 'a'] = ++cnt;
        }
        node = trie[node][s[i] - 'a'];
    }
    stop[node] = 1;
}

int search(string word, int idx) {
    int node = 0, ans = 0;
    for (int i = idx; i < word.size(); i++) {
        if (trie[node][word[i] - 'a'] == 0) {
            return ans;
        }
        node = trie[node][word[i] - 'a'];
        if (stop[node]) {
            ans = (ans + dp[i+1]) % mod;
        }
    }
    return ans;
}

int main() {
    string word;
    cin >> word;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        insert(s);
        // u[s]++; 
    }
    // cout << solve(word, 0) << endl;
    dp[word.size()] = 1;
    for (int i = word.size()-1; i >= 0; i--) {
        dp[i] = search(word, i);
    }
    cout << dp[0] << endl;
    return 0;
}