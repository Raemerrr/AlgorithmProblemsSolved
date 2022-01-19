#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> visited;
vector<int> v;

void dfs(int idx) {
    int Next = v[idx];
    if (visited[Next]) return;
    else {
        visited[Next] = true;
        dfs(Next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case = 0;
    cin >> test_case;
    while (test_case--) {
        cin >> N;
        int answer = 0;
        v.assign(N + 1, 0);
        visited.assign(N + 1, false);
        for (int i = 1; i <= N; i++) cin >> v[i];
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(i);
                answer++;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}