//(-7, -3) 0 0 X 0 0 0 0 : 0
//(-6, -6) 0 0 1 0 0 X 0 : 1
//(-5, -5) 0 0 1 0 X 1 0 : 1
//(-4, -1) X 0 1 0 1 1 0 : 0
//(-3, -7) 1 0 1 0 1 1 X : 4
//(-2, -2) 1 X 1 0 1 1 1 : 1
//(-1, -4) 1 1 1 X 1 1 1 : 3

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;
int N;
vector<LL> segmentTree;
vector<pair<int, int>> v;
LL answer;

LL update_tree(int Node, int Start, int End, int Index, LL Value) {
    if (Index < Start || End < Index) return segmentTree[Node];
    if (Start == End) return segmentTree[Node] = Value;
    int Mid = (Start + End) / 2;
    return segmentTree[Node] = update_tree(Node * 2, Start, Mid, Index, Value) +
                               update_tree(Node * 2 + 1, Mid + 1, End, Index, Value);
}

LL query_tree(int Node, int Start, int End, int Left, int Right) {
    if (Right < Start || End < Left) return 0;
    if (Left <= Start && End <= Right) return segmentTree[Node];
    int Mid = (Start + End) / 2;
    return query_tree(Node * 2, Start, Mid, Left, Right) + query_tree(Node * 2 + 1, Mid + 1, End, Left, Right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int treeHeight = (int) ceil(log2(N));
    int treeSize = (1 << (treeHeight + 1));
    v.assign(N, pair<int, int>());
    segmentTree.assign(treeSize, 0);
    for (int i = 0; i < N; i++) {
        int num = 0;
        cin >> num;
        v[i].first = -num;
        v[i].second = -i;
    }
    sort(v.begin(), v.end());
    for (const pair<int, int> &p: v) {
        answer += query_tree(1, 0, N - 1, 0, -p.second);
        update_tree(1, 0, N - 1, -p.second, 1);
    }
    cout << answer << "\n";
    return 0;
}