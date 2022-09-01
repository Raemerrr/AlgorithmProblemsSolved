#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 10;
int k;
vector<bool> visited;
vector<char> operators;
vector<string> answer;

bool good(const char before, const char after, const char op) {
    if (before < after && op == '<') return true;
    if (before > after && op == '>') return true;
    return false;
}

void dfs(const int idx, const string &num) {
    if (idx == k) {
        answer.emplace_back(num);
        return;
    }
    for (int i = 0; i < MAX; i++) {
        if (!visited[i] && good(num.back(), (char) (i + '0'), operators[idx])) {
            visited[i] = true;
            dfs(idx + 1, num + to_string(i));
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> k;
    visited.assign(MAX, false);
    operators.assign(k, ' ');
    for (int i = 0; i < k; i++) {
        cin >> operators[i];
    }
    for (int i = 0; i < MAX; i++) {
        visited[i] = true;
        dfs(0, to_string(i));
        visited[i] = false;
    }
    sort(answer.begin(), answer.end());
    cout << answer.back() << "\n";
    cout << answer[0] << "\n";
    return 0;
}