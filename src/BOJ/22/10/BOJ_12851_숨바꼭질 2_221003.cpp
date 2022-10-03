#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;
int N, K;
int visited[MAX], cnt[MAX];

bool checkRange(const int pos) {
    return -1 < pos && pos < MAX;
}

void proc() {
    queue<int> q;
    q.emplace(N);
    visited[N] = 1;
    cnt[N] = 1;
    while (!q.empty()) {
        int _front = q.front();
        q.pop();
        for (const int _next: {_front - 1, _front + 1, _front * 2}) {
            if (checkRange(_next)) {
                if (!visited[_next]) {
                    visited[_next] = visited[_front] + 1;
                    cnt[_next] += cnt[_front];
                    q.emplace(_next);
                } else if (visited[_next] == visited[_front] + 1) {
                    cnt[_next] += cnt[_front];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    proc();
    cout << visited[K] - 1 << "\n" << cnt[K] << "\n";
    return 0;
}