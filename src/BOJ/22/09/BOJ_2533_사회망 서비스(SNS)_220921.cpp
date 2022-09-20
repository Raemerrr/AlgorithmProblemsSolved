#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> nodes, dp;

void dfs() {
    vector<vector<int>> og = nodes;
    nodes.assign(N, vector<int>());
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int _front = q.front();
        q.pop();
        for (const int _next: og[_front]) {
            if (!visited[_next]) {
                visited[_next] = true;
                q.push(_next);
                nodes[_front].push_back(_next);
            }
        }
    }
}

int proc(const int index, const bool isEarlyAdopter) {
    if (dp[index][isEarlyAdopter] != -1) return dp[index][isEarlyAdopter];
    if (isEarlyAdopter) {
        //true, false
        dp[index][isEarlyAdopter] = 1;
        for (const int Next: nodes[index]) {
            dp[index][isEarlyAdopter] += min(proc(Next, true), proc(Next, false));
        }
    } else {
        dp[index][isEarlyAdopter] = 0;
        //false
        for (const int Next: nodes[index]) {
            dp[index][isEarlyAdopter] += proc(Next, true);
        }
    }
    return dp[index][isEarlyAdopter];
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
    dfs();
    cout << min(proc(0, true), proc(0, false)) << "\n";
    return 0;
}