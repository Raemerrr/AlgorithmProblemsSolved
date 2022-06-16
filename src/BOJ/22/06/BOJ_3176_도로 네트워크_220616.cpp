#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000001;
int N, M, treeHeight;
vector<vector<pair<int, int>>> nodes, dist;
vector<vector<int>> parents;
vector<int> depth;

void bfs() {
    vector<vector<pair<int, int>>> og = nodes;
    nodes.assign(N, vector<pair<int, int>>());
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int Front = q.front();
        q.pop();
        for (const pair<int, int> &p: og[Front]) {
            int Next = p.first;
            int Cost = p.second;
            if (depth[Next] == -1) {
                depth[Next] = depth[Front] + 1;
                parents[Next][0] = Front;
                nodes[Front].emplace_back(Next, Cost);
                dist[Next][0] = {Cost, Cost};
                q.emplace(Next);
            }
        }
    }
}

void make_parent() {
    for (int i = 0; i < treeHeight - 1; i++) {
        for (int j = 1; j < N; j++) {
            int parent = parents[j][i];
            if (parent != -1) {
                parents[j][i + 1] = parents[parent][i];
                dist[j][i + 1].first = min(dist[j][i].first, dist[parent][i].first);
                dist[j][i + 1].second = max(dist[j][i].second, dist[parent][i].second);
            }
        }
    }
}

void find_LCA(int a, int b) {
    int mini = MAX, maxi = -1;
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for (int i = 0; 0 < diff; i++) {
        if (diff % 2 > 0) {
            mini = min(mini, dist[a][i].first);
            maxi = max(maxi, dist[a][i].second);
            a = parents[a][i];
        }
        diff /= 2;
    }
    if (a != b) {
        for (int i = treeHeight - 1; 0 <= i; i--) {
            if (parents[a][i] != -1 && parents[a][i] != parents[b][i]) {
                mini = min(mini, dist[a][i].first);
                maxi = max(maxi, dist[a][i].second);
                a = parents[a][i];

                mini = min(mini, dist[b][i].first);
                maxi = max(maxi, dist[b][i].second);
                b = parents[b][i];
            }
        }
        mini = min(mini, dist[a][0].first);
        maxi = max(maxi, dist[a][0].second);
        a = parents[a][0];

        mini = min(mini, dist[b][0].first);
        maxi = max(maxi, dist[b][0].second);
        b = parents[b][0];
    }
    cout << mini << " " << maxi << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    treeHeight = (int) ceil(log2(N));
    nodes.assign(N, vector<pair<int, int>>());
    parents.assign(N, vector<int>(treeHeight, -1));
    depth.assign(N, -1);
    dist.assign(N, vector<pair<int, int>>(treeHeight, {MAX, -1}));
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0, cost = 0;
        cin >> a >> b >> cost;
        nodes[a - 1].emplace_back(b - 1, cost);
        nodes[b - 1].emplace_back(a - 1, cost);
    }
    depth[0] = 0;
    bfs();
    make_parent();
    cin >> M;
    while (M--) {
        int a = 0, b = 0;
        cin >> a >> b;
        find_LCA(a - 1, b - 1);
    }
    return 0;
}