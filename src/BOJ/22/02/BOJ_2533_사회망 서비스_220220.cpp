#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> nodes, dp;

void bfs() {
    vector<vector<int>> og = nodes;
    vector<bool> visited(N, false);
    nodes.assign(N, vector<int>());
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int _front = q.front();
        q.pop();
        for (const int _next: og[_front]) {
            if (!visited[_next]) {
                visited[_next] = true;
                nodes[_front].push_back(_next);
                q.push(_next);
            }
        }
    }
}

int dfs(const int _cur, const bool _flag) {
    if (dp[_cur][_flag] != -1) return dp[_cur][_flag];
    if (_flag) {
        dp[_cur][_flag] = 1;
        for (const int _next: nodes[_cur]) {
            dp[_cur][_flag] += min(dfs(_next, true), dfs(_next, false));
        }
    } else {
        dp[_cur][_flag] = 0;
        for (const int _next: nodes[_cur]) {
            dp[_cur][_flag] += dfs(_next, true);
        }
    }
    return dp[_cur][_flag];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    nodes.assign(N, vector<int>());
    dp.assign(N, vector<int>(2, -1));
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        a--, b--;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    bfs();
    cout << min(dfs(0, true), dfs(0, false)) << "\n";
    return 0;
}