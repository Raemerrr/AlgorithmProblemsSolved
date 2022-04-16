#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int N;
vector<pair<int, int>> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> position;
map<int, int> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, pair<int, int>());
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        position.push(i);
    }
    sort(v.begin(), v.end());
    for (const pair<int, int> &p: v) {
        while (!pq.empty() && pq.top().first <= p.first) {
            position.push(pq.top().second);
            pq.pop();
        }
        pq.emplace(p.second, position.top());
        answer[position.top()]++;
        position.pop();
    }
    cout << answer.size() << "\n";
    for (const pair<int, int> &p: answer) cout << p.second << " ";
    cout << "\n";
    return 0;
}