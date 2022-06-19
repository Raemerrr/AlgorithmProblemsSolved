#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int V, E, answer;
vector<pair<int, pair<int, int>>> nodes;
vector<int> parent;
map<pair<int, int>, int> m;

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
    cin >> V >> E;
    for (int i = 0; i < V; i++) parent.push_back(i);
    while (E--) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        int aa = min(a - 1, b - 1);
        int bb = max(a - 1, b - 1);
        if (m.count({aa, bb})) {
            m[{aa, bb}] = min(m[{aa, bb}], c);
        } else {
            m[{aa, bb}] = c;
        }
    }
    for (const pair<pair<int, int>, int> p: m) {
        nodes.push_back({p.second, {p.first.first, p.first.second}});
    }
    sort(nodes.begin(), nodes.end());
    for (const pair<int, pair<int, int>> &p: nodes) {
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