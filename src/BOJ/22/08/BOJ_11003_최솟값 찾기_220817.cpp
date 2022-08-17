#include <iostream>
#include <queue>

using namespace std;

int N, L;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        while (!pq.empty() && pq.top().second + L <= i) {
            pq.pop();
        }
        int num = 0;
        cin >> num;
        pq.emplace(num, i);
        cout << pq.top().first << " ";
    }
    cout << "\n";
    return 0;
}