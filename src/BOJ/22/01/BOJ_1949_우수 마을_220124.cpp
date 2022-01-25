#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> nodes, dp;
vector<int> dist;

void bfs(const int Start) {
    vector<vector<int>> og = nodes;
    nodes.assign(N, vector<int>());
    vector<bool> visited(N, false);
    visited[Start] = true;
    queue<int> q;
    q.push(Start);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (const int Next: og[front]) {
            if (!visited[Next]) {
                visited[Next] = true;
                nodes[front].push_back(Next);
                q.push(Next);
            }
        }
    }
}

int proc(const int Cur, const bool flag) {
    if (dp[Cur][flag] != -1) return dp[Cur][flag];
    if (flag) {
        dp[Cur][flag] = dist[Cur];
        for (const int Next: nodes[Cur]) {
            dp[Cur][flag] += proc(Next, false);
        }
    } else {
        dp[Cur][flag] = 0;
        for (const int Next: nodes[Cur]) {
            dp[Cur][flag] += max(proc(Next, true), proc(Next, false));
        }
    }
    return dp[Cur][flag];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    nodes.assign(N, vector<int>());
    dp.assign(N, vector<int>(2, -1));
    dist.assign(N, -1);
    for (int i = 0; i < N; i++) cin >> dist[i];
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        a--, b--;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    bfs(0);
    cout << max(proc(0, true), proc(0, false)) << "\n";
    return 0;
}