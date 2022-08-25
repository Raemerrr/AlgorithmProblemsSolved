#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100001;
vector<int> visited, route, answer;
int N, K;

void proc(const int _star) {
    queue<int> q;
    q.push(_star);
    visited[_star] = 1;
    while (!q.empty()) {
        int _cur = q.front();
        q.pop();
        for (const int _next: {_cur + 1, _cur - 1, _cur * 2}) {
            if (0 <= _next && _next <= MAX) {
                if (!visited[_next]) {
                    q.push(_next);
                    visited[_next] = visited[_cur] + 1;
                    route[_next] = _cur;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    visited.assign(MAX, 0);
    route.assign(MAX, -1);
    cin >> N >> K;
    proc(N);
    int pos = K;
    while (pos != -1) {
        answer.push_back(pos);
        pos = route[pos];
    }
    cout << visited[K] - 1 << "\n";
    while (!answer.empty()) {
        cout << answer.back() << " ";
        answer.pop_back();
    }
    cout << "\n";
    return 0;
}