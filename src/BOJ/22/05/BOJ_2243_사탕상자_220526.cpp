#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1000001;
int N;
vector<int> segmentTree;

void update_tree(int Node, int Start, int End, int Index, int Count) {
    if (Index < Start || End < Index) return;
    segmentTree[Node] += Count;
    if (Start == End) return;
    int Mid = (Start + End) / 2;
    update_tree(Node * 2, Start, Mid, Index, Count);
    update_tree(Node * 2 + 1, Mid + 1, End, Index, Count);
}

int query_tree(int Node, int Start, int End, int Count) {
    if (Start == End) return Start;
    int Mid = (Start + End) / 2;
    if (segmentTree[Node * 2] < Count) return query_tree(Node * 2 + 1, Mid + 1, End, Count - segmentTree[Node * 2]);
    return query_tree(Node * 2, Start, Mid, Count);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int treeHeight = (int) ceil(log2(INF));
    int treeSize = (1 << (treeHeight + 1));
    segmentTree.assign(treeSize, 0);
    for (int i = 0; i < N; i++) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b;
        if (a == 1) {
            int target = query_tree(1, 0, INF - 1, b);
            cout << target + 1 << "\n";
            update_tree(1, 0, INF - 1, target, -1);
        } else {
            cin >> c;
            update_tree(1, 0, INF - 1, b - 1, c);
        }
    }
    return 0;
}