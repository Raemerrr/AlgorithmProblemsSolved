#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class Data {
public:
    int pos;
    int start;
    int end;

    Data(const int pos, const int start, const int end) : pos(pos), start(start), end(end) {}

    bool operator<(const Data &data) const {
        if (this->end == data.end) {
            return this->start < data.start;
        }
        return this->end < data.end;
    }

    bool operator>(const Data &data) const {
        if (this->end == data.end) {
            return this->start > data.start;
        }
        return this->end > data.end;
    }
};

int N;
map<int, int> m;
vector<pair<int, int>> v;
priority_queue<Data, vector<Data>, greater<Data>> pq;
priority_queue<int, vector<int>, greater<int>> keys;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, pair<int, int>());
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        keys.push(i);
    }
    sort(v.begin(), v.end());
    for (const pair<int, int> &cur: v) {
        while (!pq.empty() && pq.top().end <= cur.first) {
            keys.push(pq.top().pos);
            pq.pop();
        }
        int key = keys.top();
        keys.pop();
        m[key]++;
        pq.emplace(key, cur.first, cur.second);
    }
    cout << m.size() << "\n";
    for (const pair<int, int> p: m) {
        cout << p.second << " ";
    }
    cout << "\n";
    return 0;
}