#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int>ans;
    int curr = 0, i = 0, j = s.size()-1;
    string s1 = "", s2 = "";
    while (i < s.size()-1 && j > 0) {
        s1 = s1 + s[i];
        s2 = s[j] + s2;
        if (s1 == s2) {
            // ans.push_back(i+1);
            cout << i+1 << " ";
        }
        i++;
        j--;
    }
    // sort(ans.begin(), ans.end());
    // for (int i = 0; i < ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }
    return 0;
}