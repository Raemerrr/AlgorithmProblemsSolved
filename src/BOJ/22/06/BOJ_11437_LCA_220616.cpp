#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, treeHeight;
vector<vector<int>> nodes, parents;
vector<int> depth;

void bfs() {
    vector<vector<int>> og = nodes;
    nodes.assign(N, vector<int>());
    queue<int> q;
    q.emplace(0);
    while (!q.empty()) {
        int Front = q.front();
        q.pop();
        for (const int Next: og[Front]) {
            if (depth[Next] == -1) {
                depth[Next] = depth[Front] + 1;
                parents[Next][0] = Front;
                nodes[Front].push_back(Next);
                q.push(Next);
            }
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
    nodes.assign(N, vector<int>());
    parents.assign(N, vector<int>(treeHeight, -1));
    depth.assign(N, -1);
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        nodes[a - 1].push_back(b - 1);
        nodes[b - 1].push_back(a - 1);
    }
    depth[0] = 0;
    bfs();
    make_parent();
    cin >> M;
    while (M--) {
        int a = 0, b = 0;
        cin >> a >> b;
        cout << find_LCA(a - 1, b - 1) + 1 << "\n";
    }
    return 0;
}