#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M, answer;
vector<int> v;
set<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    v.assign(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (const int d: v) {
        s.insert(d);
        int num = M - d;
        if (d == num || s.count(num)) continue;
        answer += (binary_search(v.begin(), v.end(), num) ? 1 : 0);
    }
    cout << answer << "\n";
    return 0;
}