#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H, root;
vector<int> dist, mx;
vector<vector<pair<int, int>>> nodes;

int dfs(const int cur) {
    mx[cur] = dist[cur];
    for (const pair<int, int> &d: nodes[cur]) {
        int _next = d.first;
        int _cost = d.second;
        dist[_next] = dist[cur] + _cost;
        mx[cur] = max(mx[cur], dfs(_next));
    }
    return mx[cur];
}

int solution(const int cur, const int delta) {
    int result = 0;
    for (const pair<int, int> &d: nodes[cur]) {
        int _next = d.first;
        int _cost = d.second;
        if (mx[_next] - delta <= H) continue;
        if (mx[_next] - delta - _cost <= H) result += mx[_next] - delta - H;
        else result += solution(_next, delta + _cost) + _cost;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> H;
    nodes.assign(N, vector<pair<int, int>>());
    dist.assign(N, 0);
    mx.assign(N, 0);
    for (int i = 0; i < N; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            root = i;
            continue;
        }
        a--;
        nodes[a].emplace_back(i, b);
    }
    dfs(root);
    cout << solution(root, 0) << "\n";
    return 0;
}