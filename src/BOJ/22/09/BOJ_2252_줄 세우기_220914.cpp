#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> cnt;
vector<vector<int>> nodes;

void func() {
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (cnt[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cout << front + 1 << " ";
        for (const int Next: nodes[front]) {
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
    cnt.assign(N, 0);
    nodes.assign(N, vector<int>());
    while (M--) {
        int a = 0, b = 0;
        cin >> a >> b;
        nodes[a - 1].push_back(b - 1);
        cnt[b - 1]++;
    }
    func();
    return 0;
}