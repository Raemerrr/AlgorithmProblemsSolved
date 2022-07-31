#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> cnt;
vector<vector<int>> v;

void bfs() {
    queue<int> q;
    for (int i = 0; i < N; i++) if (cnt[i] == 0) q.push(i);
    while (!q.empty()) {
        int Front = q.front();
        q.pop();
        cout << Front + 1 << " ";
        for (const int Next: v[Front]) {
            cnt[Next]--;
            if (cnt[Next] == 0) q.push(Next);
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    v.assign(N, vector<int>());
    cnt.assign(N, 0);
    for (int i = 0; i < M; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        cnt[b - 1]++;
        v[a - 1].push_back(b - 1);
    }
    bfs();
    return 0;
}