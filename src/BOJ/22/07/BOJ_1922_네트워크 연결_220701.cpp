#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer;
vector<int> parent;
vector<pair<int, pair<int, int>>> v;

int find_parent(const int key) {
    if (key == parent[key]) return key;
    return parent[key] = find_parent(parent[key]);
}

bool isSameParent(int a, int b) {
    int p1 = find_parent(a);
    int p2 = find_parent(b);
    return p1 == p2;
}

void merge_parent(int a, int b) {
    int p1 = find_parent(a);
    int p2 = find_parent(b);
    if (p1 == p2) return;
    parent[p2] = p1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) parent.push_back(i);
    for (int i = 0; i < M; i++) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        v.push_back({c, {a - 1, b - 1}});
    }
    sort(v.begin(), v.end());
    for (const pair<int, pair<int, int>> &p: v) {
        int Cur = p.second.first;
        int Next = p.second.second;
        int Cost = p.first;
        if (isSameParent(Cur, Next)) continue;
        merge_parent(Cur, Next);
        answer += Cost;
    }
    cout << answer << "\n";
    return 0;
}