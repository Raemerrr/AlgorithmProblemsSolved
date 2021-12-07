#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int N, M;
vector<pair<int, pair<string, int>>> v;
set<int> s;
map<int, set<pair<int, string>>> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    v.assign(M, pair<int, pair<string, int>>());
    for (int i = 0; i < M; i++) {
        v[i].first = i;
        cin >> v[i].second.first >> v[i].second.second;
    }
    sort(v.begin(), v.end(), [](const pair<int, pair<string, int>> &a, const pair<int, pair<string, int>> &b) {
        if (a.second.second == b.second.second) {
            return a.first < b.first;
        }
        return a.second.second < b.second.second;
    });
    for (const pair<int, pair<string, int>> &d: v) {
        if (!s.count(d.second.second)) {
            s.insert(d.second.second);
            auto uIt = upper_bound(v.begin(), v.end(), d,
                                   [](const pair<int, pair<string, int>> &a, const pair<int, pair<string, int>> &b) {
                                       return a.second.second < b.second.second;
                                   });
            auto lIt = lower_bound(v.begin(), v.end(), d,
                                   [](pair<int, pair<string, int>> lhs,
                                      pair<int, pair<string, int>> rhs) -> bool {
                                       return lhs.second.second < rhs.second.second;
                                   });
            int cnt = uIt - lIt;
            m[cnt].insert({(*lIt).second.second, (*lIt).second.first});
        }
    }
    cout << (*(*m.begin()).second.begin()).second << " " << (*(*m.begin()).second.begin()).first << "\n";
    return 0;
}