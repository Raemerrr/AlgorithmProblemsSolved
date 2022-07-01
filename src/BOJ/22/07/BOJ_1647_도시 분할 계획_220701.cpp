#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer, sub;
vector<pair<int, pair<int, int>>> v;
vector<int> parent;

int findParent(const int key) {
    if (key == parent[key]) return key;
    return parent[key] = findParent(parent[key]);
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
    for (int i = 0; i < N; i++) parent.push_back(i);
    for (int i = 0; i < M; i++) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        v.push_back({c, {a - 1, b - 1}});
    }
    sort(v.begin(), v.end());
    for (const pair<int, pair<int, int>> &p: v) {
        int p1 = findParent(p.second.first);
        int p2 = findParent(p.second.second);
        if (p1 == p2) continue;
        mergeParent(p1, p2);
        answer += p.first;
        sub = p.first;
    }
    cout << answer - sub << "\n";
    return 0;
}