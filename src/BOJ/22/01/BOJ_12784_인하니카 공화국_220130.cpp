#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int N, M, answer;
vector<vector<pair<int, int>>> nodes, init;
vector<bool> visited;
vector<vector<int>> dist;

void dfs(const int idx) {
    visited[idx] = true;
    for (const pair<int, int> &Next: init[idx]) {
        if (!visited[Next.first]) {
            visited[Next.first] = true;
            nodes[idx].emplace_back(Next.first, Next.second);
            dfs(Next.first);
        }
    }
}

int solution(const int idx, const int prev) {
    int result = dist[idx][prev];
    int sum = 0;
    for (const pair<int, int> &Next: nodes[idx]) {
        sum += solution(Next.first, idx);
    }
    return ((sum != 0) ? min(sum, result) : result);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case = 0;
    cin >> test_case;
    while (test_case--) {
        cin >> N >> M;
        nodes.assign(N, vector<pair<int, int>>());
        init.assign(N, vector<pair<int, int>>());
        dist.assign(N, vector<int>(N, INF));
        visited.assign(N, false);
        for (int i = 0; i < M; i++) {
            int a = 0, b = 0, c = 0;
            cin >> a >> b >> c;
            a--, b--;
            init[a].emplace_back(b, c);
            init[b].emplace_back(a, c);
            dist[a][b] = c;
            dist[b][a] = c;
        }
        dfs(0);
        answer = solution(0, 0);
        cout << ((answer != INF) ? answer : 0) << "\n";
    }
    return 0;
}