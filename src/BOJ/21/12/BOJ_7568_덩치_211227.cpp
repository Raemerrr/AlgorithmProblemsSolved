#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;
vector<int> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, pair<int, int>(0, 0));
    answer.assign(N, 1);
    for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && v[i].first < v[j].first && v[i].second < v[j].second) {
                answer[i]++;
            }
        }
    }
    for (const int d: answer) cout << d << " ";
    cout << "\n";
    return 0;
}

