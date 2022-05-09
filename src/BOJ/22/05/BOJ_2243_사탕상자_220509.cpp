#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000001;
vector<int> segmentTree;
int N;

void update_tree(int Node, int Start, int End, int Index, int Value) {
    if (Index < Start || End < Index) return;
    segmentTree[Node] += Value;
    if (Start == End) return;
    int Mid = (Start + End) / 2;
    update_tree(Node * 2, Start, Mid, Index, Value);
    update_tree(Node * 2 + 1, Mid + 1, End, Index, Value);
}

int query_tree(int Node, int Start, int End, int Count) {
    if (Start == End) return Start;
    int Mid = (Start + End) / 2;
    if (Count <= segmentTree[Node * 2]) return query_tree(Node * 2, Start, Mid, Count);
    return query_tree(Node * 2 + 1, Mid + 1, End, Count - segmentTree[Node * 2]);
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
            int target = query_tree(1, 1, MAX - 1, b);
            cout << target << "\n";
            update_tree(1, 1, MAX - 1, target, -1);

        } else {
            cin >> c;
            update_tree(1, 1, MAX - 1, b, c);
        }
    }
    return 0;
}