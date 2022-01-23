#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, treeHeight, root;
vector<vector<int>> nodes, parent;
vector<int> depth, cnt;

void dfs(const int Cur) {
    for (const int Next: nodes[Cur]) {
        if (depth[Next] == -1) {
            depth[Next] = depth[Cur] + 1;
            parent[Next][0] = Cur;
            dfs(Next);
        }
    }
}

void make_parent() {
    for (int i = 0; i < treeHeight - 1; i++) {
        for (int j = 1; j < N; j++) {
            if (parent[j][i] != -1) {
                parent[j][i + 1] = parent[parent[j][i]][i];
            }
        }
    }
}

int find_LCA(const int _a, const int _b) {
    int a = _a;
    int b = _b;
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for (int i = 0; 0 < diff; i++) {
        if (diff % 2 > 0) {
            a = parent[a][i];
        }
        diff /= 2;
    }
    if (a != b) {
        for (int i = treeHeight - 1; 0 <= i; i--) {
            if (parent[a][i] != -1 && parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        a = parent[a][0];
    }
    return a + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case = 0;
    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        cin >> N;
        treeHeight = (int) ceil(log2(N));
        nodes.assign(N, vector<int>());
        parent.assign(N, vector<int>(treeHeight, -1));
        depth.assign(N, -1);
        cnt.assign(N, 0);
        for (int i = 0; i < N - 1; i++) {
            int a = 0, b = 0;
            cin >> a >> b;
            a--, b--;
            nodes[a].push_back(b);
            cnt[b]++;
        }
        for (int i = 0; i < N; i++) {
            if (cnt[i] == 0) {
                root = i;
                break;
            }
        }
        depth[root] = 0;
        dfs(root);
        make_parent();
        int c = 0, d = 0;
        cin >> c >> d;
        c--, d--;
        cout << find_LCA(c, d) << "\n";
    }
    return 0;
}