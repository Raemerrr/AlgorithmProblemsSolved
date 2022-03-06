#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 0, answer = 0;
    vector<int> price(4, 0);
    vector<pair<int, int>> v(3, pair<int, int>());
    for (int i = 1; i <= 3; i++) cin >> price[i];
    for (int i = 0; i < 3; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == v[j].first) cnt++;
            if (i == v[j].second) cnt--;
        }
        answer += price[cnt] * cnt;
    }
    cout << answer << "\n";
    return 0;
}