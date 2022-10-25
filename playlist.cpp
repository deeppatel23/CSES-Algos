#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int>play(n);
//     for (int i = 0; i < n; i++) {
//         cin >> play[i];
//     }

//     int ans = 1;
//     unordered_map<int, int>u;
//     for (int i = 0; i < n; i++) {
//         if (u.find(play[i]) == u.end()) {
//             u[play[i]] = i;
//         }
//         else {
//             int sz = u.size();
//             ans = max(ans, sz);
//             int prev = u[play[i]];
//             for (int j = prev; j >= 0; j--) {
//                 if (u[play[j]] <= prev)
//                     u.erase(play[j]);
//                 if (j != prev && play[j] == play[prev]) {
//                     break;
//                 }
//             }
//             u[play[i]] = i;
//         }
//         // cout << u.size() << " ";
//     }
//     int sz = u.size();
//     ans = max(ans, sz);
//     cout << ans << endl;
//     return 0;
// }

int main() {
    int n;
    cin >> n;
    vector<int>play(n);
    for (int i = 0; i < n; i++) {
        cin >> play[i];
    }

    int i = 0, j = 0, max_len = 0, curr_len = 0;
	unordered_map<int, int> freq;
	while (j < n)
	{
		if (freq.find(play[j]) == freq.end() || freq[play[j]] == 0)
		{
			freq[play[j]]++;
			curr_len++;
			max_len = max(max_len, curr_len);
			j++;
		}
		else
		{
			curr_len--;
			freq[play[i]]--;
			i++;
		}
	}
	cout << max_len << endl;
    return 0;
}