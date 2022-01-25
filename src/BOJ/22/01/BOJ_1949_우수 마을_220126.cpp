#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<int> dist;
vector<vector<int>> nodes, dp;

int solution(const int idx, const bool flag) {
    if (dp[idx][flag] != -1) return dp[idx][flag];
    if (flag) {
        dp[idx][flag] = dist[idx];
        for (const int Next: nodes[idx]) {
            dp[idx][flag] += solution(Next, false);
        }
    } else {
        dp[idx][flag] = 0;
        for (const int Next: nodes[idx]) {
            dp[idx][flag] += max(solution(Next, true), solution(Next, false));
        }
    }
    return dp[idx][flag];
}

void bfs(const int Start) {
    vector<vector<int>> og = nodes;
    nodes.assign(N, vector<int>());
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(Start);
    visited[Start] = true;
    while (!q.empty()) {
        int Front = q.front();
        q.pop();
        for (const int Next: og[Front]) {
            if (!visited[Next]) {
                visited[Next] = true;
                nodes[Front].push_back(Next);
                q.push(Next);
            }
        }
    }
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
    cout << max(solution(0, true), solution(0, false)) << "\n";
    return 0;
}