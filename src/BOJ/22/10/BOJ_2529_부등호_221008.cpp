#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 10;
int K;
vector<char> operators;
vector<bool> visited;
vector<string> answer;

bool isGood(const char before, const char after, const char op) {
    if (op == '<' && before < after) return true;
    if (op == '>' && before > after) return true;
    return false;
}

void dfs(const string &s, const int idx) {
    if (idx == K) {
        answer.push_back(s);
        return;
    }
    for (int i = 0; i < MAX; i++) {
        if (!visited[i] && isGood(s.back(), ((char) i + '0'), operators[idx])) {
            visited[i] = true;
            dfs(s + to_string(i), idx + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> K;
    operators.assign(K, ' ');
    visited.assign(MAX, false);
    for (int i = 0; i < K; i++) cin >> operators[i];
    for (int i = 0; i < MAX; i++) {
        visited[i] = true;
        dfs(to_string(i), 0);
        visited[i] = false;
    }
    sort(answer.begin(), answer.end());
    cout << answer.back() << "\n";
    cout << answer[0] << "\n";
    return 0;
}