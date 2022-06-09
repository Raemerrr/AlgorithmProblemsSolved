#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 1000000;
int N;
vector<int> segmentTree;

void update_tree(int Node, int Start, int End, int Index, int Value) {
    if (Index < Start || End < Index) return;
    segmentTree[Node] += Value;
    if (Start == End) return;
    int Mid = (Start + End) / 2;
    update_tree(Node * 2, Start, Mid, Index, Value);
    update_tree(Node * 2 + 1, Mid + 1, End, Index, Value);
}

int query_tree(int Node, int Start, int End, int Cnt) {
    if (Start == End) return Start;
    int Mid = (Start + End) / 2;
    if (Cnt <= segmentTree[Node * 2]) return query_tree(Node * 2, Start, Mid, Cnt);
    return query_tree(Node * 2 + 1, Mid + 1, End, Cnt - segmentTree[Node * 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int treeHeight = (int) ceil(log2(MAX));
    int treeSize = (1 << (treeHeight + 1));
    segmentTree.assign(treeSize, 0);
    while (N--) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b;
        if (a == 1) {
            int target = query_tree(1, 0, MAX - 1, b);
            update_tree(1, 0, MAX - 1, target, -1);
            cout << target + 1 << "\n";
        } else {
            cin >> c;
            update_tree(1, 0, MAX - 1, b - 1, c);
        }
    }
    return 0;
}