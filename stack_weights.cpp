#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<int, int> >v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    int left = 0, right = 0, nl = 0, nr = 0;
    for (int i = 0; i < n; i++) {
        v[i].second == 1 ? left += v[i].first, nl++ : right += v[i].first, nr++;
        if (left > right && nl >= nr) {
            cout << ">" << endl; 
        }
        else if (right > left && nr >= nl) {
            cout << "<" << endl;
        }
        else {
            cout << "?" << endl;
        }
    }
    return 0;
}