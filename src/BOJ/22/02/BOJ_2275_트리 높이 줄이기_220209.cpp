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
        dist[d.first] = dist[cur] + d.second;
        mx[cur] = max(mx[cur], dfs(d.first));
    }
    return mx[cur];
}

int solution(const int cur, const int delta) {
    int result = 0;
    for (const pair<int, int> &d: nodes[cur]) {
        if (mx[d.first] - delta <= H) continue;
        if (mx[d.first] - delta - d.second <= H) result += mx[d.first] - delta - H;
        else result += solution(d.first, delta + d.second) + d.second;
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