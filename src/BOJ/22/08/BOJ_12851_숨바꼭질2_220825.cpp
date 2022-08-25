#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;

int visited[MAX], cnt[MAX];
int a, b;

void proc(int _start) {
    queue<int> q;
    q.emplace(_start);
    visited[_start] = 1;
    cnt[_start] = 1;
    while (!q.empty()) {
        int _cur = q.front();
        q.pop();
        for (int _next: {_cur + 1, _cur - 1, _cur * 2}) {
            if (0 <= _next && _next <= MAX) {
                if (!visited[_next]) {
                    q.push(_next);
                    visited[_next] = visited[_cur] + 1;
                    cnt[_next] += cnt[_cur];
                } else if (visited[_next] == visited[_cur] + 1) {
                    cnt[_next] += cnt[_cur];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    proc(a);
    cout << visited[b] - 1 << "\n";
    cout << cnt[b] << "\n";
    return 0;
}
