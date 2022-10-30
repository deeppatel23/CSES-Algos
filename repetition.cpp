#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int curr = 1, maxx = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) {
            curr++;
        }
        else {
            maxx = max(maxx, curr);
            curr = 1;
        }
    }
    maxx = max(maxx, curr);
    cout << maxx << endl;
    return 0;
}