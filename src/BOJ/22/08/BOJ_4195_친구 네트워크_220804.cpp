#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> parentRank;
map<string, string> parent;
int test_case, N;

void initParent(const string &me) {
    if (!parent.count(me)) {
        parent[me] = me;
        parentRank[me] = 1;
    }
}

string find_parent(const string &me) {
    if (parent[me] == me) return me;
    return parent[me] = find_parent(parent[me]);
}

void merge_parent(const string &a, const string &b) {
    string aa = find_parent(a);
    string bb = find_parent(b);
    if (aa == bb) return;
    if (parentRank[aa] < parentRank[bb]) {
        swap(aa, bb);
    }
    parentRank[aa] += parentRank[bb];
    parentRank[bb] = 0;
    parent[bb] = aa;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> test_case;
    while (test_case--) {
        parentRank.clear();
        parent.clear();
        cin >> N;
        for (int i = 0; i < N; i++) {
            string str1, str2;
            cin >> str1 >> str2;
            initParent(str1);
            initParent(str2);
            merge_parent(str1, str2);
            cout << parentRank[find_parent(str1)] << "\n";
        }
    }
    return 0;
}