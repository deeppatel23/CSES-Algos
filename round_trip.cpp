#include<bits/stdc++.h>
using namespace std;

bool isCycle (vector<int>adj[], vector<bool>&vis, vector<int>&cyc, int s, int p) {
    vis[s]=1;
    for (auto i: adj[s]) {
        cyc.push_back(i);
        if (!vis[i]) {
            if (isCycle(adj, vis, cyc, i,s)) 
                return 1;
        }
        else if (i!=p) {
            return 1;
        }
        cyc.pop_back();
    }
    return 0;
}

void removeRedundant(vector<int>&path) {
    map<int, int>m;
    int st = -1, ed = -1;
    for (int i = 0; i < path.size(); i++) {
        if (m.find(path[i]) == m.end()) {
            m[path[i]] = i;
        }
        else {
            st = m[path[i]];
            ed = i;
            break;
        }
    }
    if (st == -1) {
        return;
    }
    vector<int>temp;
    for (int i = st; i <= ed; i++) {
        temp.push_back(path[i]);
    }
    path = temp;
    return;
}

 int main() {
    int n, m;
    cin >> n >> m;
    vector<int>adj[n+1];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool>vis(n+1, false);
    bool possible = false;

    for (int i = 1; i <= n; i++) {
        vector<int>path;
        // vector<bool>vis(n+1, false);
        if (!vis[i]) {
            vis[i] = true;
            path.push_back(i);
            if (isCycle(adj, vis, path, i, 0)) {
                removeRedundant(path);
                if (path.size() >= 4) {
                    cout << path.size() << endl;
                    possible = true;
                    for (int i = 0; i < path.size(); i++)
                        cout << path[i] << " ";
                    cout << endl;
                    break;
                }
            }
        }
    }
    if (!possible) {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}