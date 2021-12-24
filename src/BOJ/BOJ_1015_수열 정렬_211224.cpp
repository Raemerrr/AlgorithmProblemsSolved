#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v, temp;
vector<bool> visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, 0);
    visited.assign(N, false);
    for (int i = 0; i < N; i++) cin >> v[i];
    temp = v;
    sort(temp.begin(), temp.end());
    for (const int d: v) {
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == d && !visited[i]) {
                cout << i << " ";
                visited[i] = true;
                break;
            }
        }
    }
    return 0;
}