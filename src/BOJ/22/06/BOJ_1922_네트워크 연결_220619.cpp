#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer;
vector<pair<int, pair<int, int>>> node;
vector<int> parent;

int findParent(const int key) {
    if (parent[key] == key) return key;
    return parent[key] = findParent(parent[key]);
}

bool isSameParent(const int a, const int b) {
    return findParent(a) == findParent(b);
}

void mergeParent(const int a, const int b) {
    int p1 = findParent(a);
    int p2 = findParent(b);
    if (p1 == p2) return;
    parent[p2] = p1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    parent.assign(N, 0);
    for (int i = 0; i < N; i++) parent[i] = i;
    for (int i = 0; i < M; i++) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        node.push_back({c, {a - 1, b - 1}});
    }
    sort(node.begin(), node.end());
    for (const pair<int, pair<int, int>> &p: node) {
        int Cost = p.first;
        int Cur = p.second.first;
        int Next = p.second.second;
        if (isSameParent(Cur, Next)) continue;
        mergeParent(Cur, Next);
        answer += Cost;
    }
    cout << answer << "\n";
    return 0;
}