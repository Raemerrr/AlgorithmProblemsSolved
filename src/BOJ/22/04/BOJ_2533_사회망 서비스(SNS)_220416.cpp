#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> nodes, dp;

void bfs(int _start) {
    vector<vector<int>> og = nodes;
    nodes.assign(N, vector<int>());
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(_start);
    visited[_start] = true;
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

int dfs(int _index, bool _flag) {
    if (dp[_index][_flag] != -1) return dp[_index][_flag];
    if (_flag) {
        dp[_index][_flag] = 1;
        for (const int _next: nodes[_index]) {
            dp[_index][_flag] += min(dfs(_next, true), dfs(_next, false));
        }
    } else {
        dp[_index][_flag] = 0;
        for (const int _next: nodes[_index]) {
            dp[_index][_flag] += dfs(_next, true);
        }
    }
    return dp[_index][_flag];
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
        nodes[a - 1].push_back(b - 1);
        nodes[b - 1].push_back(a - 1);
    }
    bfs(0);
    cout << min(dfs(0, true), dfs(0, false)) << "\n";
    return 0;
}