#include <iostream>
#include <vector>
#include <map>

using namespace std;

int test_case, N;
map<string, string> parent;
map<string, int> parentRank;

void initParent(const string &key) {
    if (!parent.count(key)) {
        parent[key] = key;
        parentRank[key] = 1;
    }
}

string findParent(const string &key) {
    if (key == parent[key]) return key;
    return parent[key] = findParent(parent[key]);
}

void mergeParent(const string &a, const string &b) {
    string aa = findParent(a);
    string bb = findParent(b);
    if (aa == bb) return;
    parent[bb] = aa;
    parentRank[aa] += parentRank[bb];
    parentRank[bb] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> test_case;
    while (test_case--) {
        cin >> N;
        parent.clear();
        parentRank.clear();
        for (int i = 0; i < N; i++) {
            string str1, str2;
            cin >> str1 >> str2;
            initParent(str1);
            initParent(str2);
            mergeParent(str1, str2);
            cout << parentRank[findParent(str1)] << "\n";
        }
    }
    return 0;
}