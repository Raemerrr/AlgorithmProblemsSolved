#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W;
vector<string> v;
vector<vector<int>> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> W;
    v.assign(H, string(W, ' '));
    answer.assign(H, vector<int>(W, -1));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> v[i][j];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (v[i][j] == 'c') {
                answer[i][j] = 0;
            } else {
                answer[i][j] = ((j > 0 && answer[i][j - 1] != -1) ? answer[i][j - 1] + 1 : answer[i][j]);
            }
        }
    }
    for (const vector<int> &d: answer) {
        for (int i: d) cout << i << " ";
        cout << "\n";
    }
    return 0;
}