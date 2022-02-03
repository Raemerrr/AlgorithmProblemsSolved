#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> cost, v;
vector<vector<int>> nodes, dp;

int dfs(int Cur, int Prev, bool flag) {
    if (dp[Cur][flag] != -1) return dp[Cur][flag];
    dp[Cur][flag] = flag ? cost[Cur] : 0;
    for (const int Next: nodes[Cur]) {
        if (Next == Prev) continue;
        if (flag) dp[Cur][flag] += dfs(Next, Cur, false);
        else dp[Cur][flag] += max(dfs(Next, Cur, true), dfs(Next, Cur, false));
    }
    return dp[Cur][flag];
}

void back_tracking(int Cur, int Prev, bool flag) {
    if (flag) v.push_back(Cur + 1);
    for (const int Next: nodes[Cur]) {
        if (Next == Prev) continue;
        if (flag) back_tracking(Next, Cur, false);
        else back_tracking(Next, Cur, dfs(Next, Cur, false) < dfs(Next, Cur, true));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cost.assign(N, -1);
    nodes.assign(N, vector<int>());
    dp.assign(N, vector<int>(2, -1));
    for (int i = 0; i < N; i++) cin >> cost[i];
    for (int i = 1; i < N; i++) {
        int num = 0;
        cin >> num;
        num--;
        nodes[num].push_back(i);
        nodes[i].push_back(num);
    }
    cout << dfs(0, -1, true) << ' ' << dfs(0, -1, false) << '\n';
    back_tracking(0, -1, true);
    sort(v.begin(), v.end());
    for (const int d: v) cout << d << " ";
    cout << "-1\n";
    v.clear();
    back_tracking(0, -1, false);
    sort(v.begin(), v.end());
    for (const int d: v) cout << d << " ";
    cout << "-1\n";
    v.clear();
    return 0;
}