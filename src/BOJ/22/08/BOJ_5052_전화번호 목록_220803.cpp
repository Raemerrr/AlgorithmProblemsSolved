#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int test_case, N;
map<char, set<string>> m;
vector<string> v;

string proc() {
    sort(v.begin(), v.end());
    for (const string &s: v) {
        string temp;
        for (int i = 0; i < s.size() - 1; i++) {
            temp += s[i];
            if (m[s[0]].count(temp)) return "NO";
        }
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> test_case;
    while (test_case--) {
        m.clear();
        cin >> N;
        v.assign(N, "");
        for (int i = 0; i < N; i++) {
            cin >> v[i];
            m[v[i][0]].insert(v[i]);
        }
        cout << proc() << "\n";
    }
    return 0;
}