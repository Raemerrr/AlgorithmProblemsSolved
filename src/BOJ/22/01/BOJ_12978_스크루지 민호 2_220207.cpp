#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> nodes, dp;

int dfs(int cur, int prev, bool flag) {
    if (dp[cur][flag] != -1) return dp[cur][flag];
    // 이전에 최솟값이 계산된 적이 없다면, 처음 경찰서 수 설정
    dp[cur][flag] = (flag) ? 1 : 0;
    for (const int nxt: nodes[cur]) {
        // 다음 방문지가 이전 방문지가 아닐때만 방문
        if (nxt != prev) {
            if (flag) {
                // 현재 방문지에 경찰서가 있다면 다음 방문지에 경찰서가 있거나, 없어도 된다.
                dp[cur][flag] += min(dfs(nxt, cur, true), dfs(nxt, cur, false));
            } else {
                // 현재 방문지에 경찰서가 없다면 다음 방문지에 경찰서가 있어야 한다.
                dp[cur][flag] += dfs(nxt, cur, true);
            }
        }
    }
    return dp[cur][flag];
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
    cout << min(dfs(0, -1, true), dfs(0, -1, false)) << "\n";
    return 0;
}