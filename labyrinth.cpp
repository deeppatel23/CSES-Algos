#include<bits/stdc++.h>
using namespace std;

string ans;
// void dfs(vector<vector<char> >&g, vector<vector<bool> >&vis, int i, int j, string s) {
//     int n = g.size(), m = g[0].size();
//     if (i < 0 || j < 0 || i >= n || j >= m || g[i][j] == '#' || vis[i][j] || (s.size() > ans.size() && ans.size() != 0)) {
//         return;
//     }
//     if (g[i][j] == 'B') {
//         if (ans.size() == 0 || ans.size() > s.size()) 
//             ans = s;
//     }
//     vis[i][j] = true;
//     dfs(g, vis, i+1, j, s+'D');
//     dfs(g, vis, i-1, j, s+'U');
//     dfs(g, vis, i, j+1, s+'R');
//     dfs(g, vis, i, j-1, s+'L');
//     vis[i][j] = false;
// }

void bfs(vector<vector<char> >&g, int starti, int startj) {
    int n = g.size(), m = g[0].size();
    queue<pair<int, int> >q;
    q.push(make_pair(starti, startj));
    bool found = false;
    int endi, endj;
    // cout << starti << startj << "\n";

    while (!found && !q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if (i+1 < n && (g[i+1][j] == '.' || g[i+1][j] == 'B')) { 
            q.push(make_pair(i+1, j));
            if (g[i+1][j] == 'B') {
                found = true;
                endi = i+1;
                endj = j;
            }
            g[i+1][j] = 'D';
        }
        if (i-1 >= 0 && (g[i-1][j] == '.' || g[i-1][j] == 'B')) {
            q.push(make_pair(i-1, j));
            if (g[i-1][j] == 'B') {
                found = true;
                endi = i-1;
                endj = j;
            }
            g[i-1][j] = 'U';
        }
        if (j+1 < m && (g[i][j+1] == '.' || g[i][j+1] == 'B')) {
            q.push(make_pair(i, j+1));
            if (g[i][j+1] == 'B') {
                found = true;
                endi = i;
                endj = j+1;
            }
            g[i][j+1] = 'R';
        }
        if (j-1 >= 0 && (g[i][j-1] == '.' || g[i][j-1] == 'B')) { 
            q.push(make_pair(i, j-1));
            if (g[i][j-1] == 'B') {
                found = true;
                endi = i;
                endj = j-1;
            }
            g[i][j-1] = 'L';
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (!found)
        return;
    int curri = endi, currj = endj; 
    while(!(curri==starti && currj==startj)){
		ans += g[curri][currj];
		switch(g[curri][currj]){
			case 'D':
				curri--;
				break;
			case 'U':
				curri++;
				break;
			case 'R':
				currj--;
				break;
			case 'L':
				currj++;
				break;
		}
	}
    reverse(ans.begin(), ans.end());
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> >grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    ans = "";
    vector<vector<bool> >vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                string s;
                // dfs(grid, vis, i, j, s);
                bfs(grid, i, j);
                break;
            }
        }
    }

    if (ans.size() == 0)
        cout << "NO\n";
    else
        cout << "YES\n" << ans.size() << endl << ans << endl;
    return 0;
}