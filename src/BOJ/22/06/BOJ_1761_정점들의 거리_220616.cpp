#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, treeHeight;
vector<vector<pair<int, int>>> nodes;
vector<vector<int>> parents;
vector<int> depth, dist;

void dfs(const int Cur) {
    for (const pair<int, int> &p: nodes[Cur]) {
        int Next = p.first;
        int Cost = p.second;
        if (depth[Next] == -1) {
            depth[Next] = depth[Cur] + 1;
            parents[Next][0] = Cur;
            dist[Next] = dist[Cur] + Cost;
            dfs(Next);
        }
    }
}

void make_parent() {
    for (int i = 0; i < treeHeight - 1; i++) {
        for (int j = 1; j < N; j++) {
            if (parents[j][i] != -1) {
                parents[j][i + 1] = parents[parents[j][i]][i];
            }
        }
    }
}

int find_LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for (int i = 0; 0 < diff; i++) {
        if (diff % 2 > 0) {
            a = parents[a][i];
        }
        diff /= 2;
    }
    if (a != b) {
        for (int i = treeHeight - 1; 0 <= i; i--) {
            if (parents[a][i] != -1 && parents[a][i] != parents[b][i]) {
                a = parents[a][i];
                b = parents[b][i];
            }
        }
        a = parents[a][0];
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    treeHeight = (int) ceil(log2(N));
    nodes.assign(N, vector<pair<int, int>>());
    parents.assign(N, vector<int>(treeHeight, -1));
    dist.assign(N, 0);
    depth.assign(N, -1);
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        nodes[a - 1].emplace_back(b - 1, c);
        nodes[b - 1].emplace_back(a - 1, c);
    }
    depth[0] = 0;
    dist[0] = 0;
    dfs(0);
    make_parent();
    cin >> M;
    while (M--) {
        int a = 0, b = 0;
        cin >> a >> b;
        int lca = find_LCA(a - 1, b - 1);
        cout << dist[a - 1] + dist[b - 1] - (dist[lca] * 2) << "\n";
    }
    return 0;
}