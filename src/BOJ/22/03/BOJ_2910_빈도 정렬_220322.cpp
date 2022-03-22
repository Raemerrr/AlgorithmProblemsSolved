#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, C;
vector<pair<int, int>> v;
map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> C;
    v.reserve(N);
    for (int i = 0; i < N; i++) {
        int num = 0;
        cin >> num;
        if (!m.count(num)) v.emplace_back(num, i);
        m[num]++;
    }
    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (m[a.first] == m[b.first]) return a.second < b.second;
        return m[a.first] > m[b.first];
    });
    for (const pair<int, int> &d: v) {
        for (int i = 0; i < m[d.first]; i++) {
            cout << d.first << " ";
        }
    }
    cout << "\n";
    return 0;
}