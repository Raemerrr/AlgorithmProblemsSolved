#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> v, dp;
vector<bool> visited;


void bfs() {
    int Start = 0;
    vector<vector<int>> og = v;
    v.assign(N, vector<int>());
    queue<int> q;
    q.push(Start);
    visited[Start] = true;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (const int Next: og[front]) {
            if (!visited[Next]) {
                v[front].push_back(Next);
                q.push(Next);
                visited[Next] = true;
            }
        }
    }
}

int solution(int Cur, bool flag) {
    if (dp[Cur][flag] != -1) {
        return dp[Cur][flag];
    }
    if (flag) {
        dp[Cur][flag] = 1;
        for (const int Next: v[Cur]) {
            dp[Cur][flag] += min(solution(Next, true), solution(Next, false));
        }
    } else {
        dp[Cur][flag] = 0;
        for (const int Next: v[Cur]) {
            dp[Cur][flag] += solution(Next, true);
        }
    }
    return dp[Cur][flag];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, vector<int>());
    visited.assign(N, false);
    dp.assign(N, vector<int>(2, -1));
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }
    bfs();
    cout << min(solution(0, true), solution(0, false)) << "\n";
    return 0;
}