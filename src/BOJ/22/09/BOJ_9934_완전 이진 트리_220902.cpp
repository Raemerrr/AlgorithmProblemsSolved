#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> v;
vector<vector<int>> answer;

void dfs(const int level, const vector<int> &arr) {
    if (level == N) {
        answer[level - 1].insert(answer[level - 1].end(), arr.begin(), arr.end());
        return;
    }
    vector<int> _left = vector<int>(arr.begin(), arr.begin() + arr.size() / 2);
    dfs(level + 1, _left);
    int mid = arr[arr.size() / 2];
    vector<int> _right = vector<int>(arr.begin() + (arr.size() / 2) + 1, arr.end());
    dfs(level + 1, _right);
    answer[level - 1].push_back(mid);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    answer.assign(N, vector<int>());
    int treeSize = pow(2, N) - 1;
    v.assign(treeSize, 0);
    for (int i = 0; i < treeSize; i++) cin >> v[i];
    dfs(1, v);
    for (const vector<int> &z: answer) {
        for (const int d: z) {
            cout << d << " ";
        }
        cout << "\n";
    }
    return 0;
}
