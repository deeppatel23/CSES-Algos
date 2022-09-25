#include<bits/stdc++.h>
using namespace std;

int main {
    int n;
    cin >> n;
    vector<int>adj[n];
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    

    return 0;
}