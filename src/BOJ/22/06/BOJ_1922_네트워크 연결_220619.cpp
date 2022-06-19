#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer;
vector<pair<int, pair<int, int>>> node;
vector<int> parent;

int find_parent(const int a) {
    if (parent[a] == a) return a;
    return parent[a] = find_parent(parent[a]);
}

bool isSameParent(const int a, const int b) {
    int p1 = find_parent(a);
    int p2 = find_parent(b);
    return p1 == p2;
}

void merge_parent(const int a, const int b) {
    int p1 = find_parent(a);
    int p2 = find_parent(b);
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
        merge_parent(Cur, Next);
        answer += Cost;
    }
    cout << answer << "\n";
    return 0;
}