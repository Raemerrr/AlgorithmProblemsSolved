#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Data {
public:
    int id;
    int first;
    int second;

    Data() {}
    Data(const int first, const int second) : id(-1), first(first), second(second) {}
    Data(const int id, const int first, const int second) : id(id), first(first), second(second) {}

    bool operator<(const Data &other) const {
        if (other.second == this->second) {
            return other.first < this->first;
        }
        return other.second < this->second;
    }
};

const int MAX = 100001;
int N, answer;
vector<Data> v;
vector<int> cnt;

void proc() {
    sort(v.begin(), v.end(), [](const Data &a, const Data &b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    priority_queue<int, vector<int>, greater<int>> idxQ;
    for (int i = 0; i < MAX; i++) idxQ.push(i);
    priority_queue<Data> pq;
    for (const Data &d: v) {
        while (!pq.empty() && pq.top().second <= d.first) {
            Data data = pq.top();
            idxQ.push(data.id);
            pq.pop();
        }
        int idx = idxQ.top();
        idxQ.pop();
        pq.emplace(idx, d.first, d.second);
        cnt[idx]++;
        answer = max(answer, (int) pq.size());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    cnt.assign(MAX, 0);
    for (int i = 0; i < N; i++) {
        int num1 = 0, num2 = 0;
        cin >> num1 >> num2;
        v.emplace_back(num1, num2);
    }
    proc();
    cout << answer << "\n";
    for (int i = 0; i < answer; i++) {
        cout << cnt[i] << " ";
    }
    cout << "\n";
    return 0;
}