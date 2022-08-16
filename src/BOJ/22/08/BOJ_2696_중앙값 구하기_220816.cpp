#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, mid;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case = 0;
    cin >> test_case;
    while (test_case--) {
        cin >> N;
        priority_queue<int> minQ;
        priority_queue<int, vector<int>, greater<int>> maxQ;
        vector<int> answer;
        cin >> mid;
        answer.push_back(mid);
        for (int i = 0; i < N - 1; i++) {
            int num = 0;
            cin >> num;
            if (num <= mid) {
                minQ.push(num);
            } else {
                maxQ.push(num);
            }
            if (i % 2 != 0) {
                if (minQ.size() < maxQ.size()) {
                    minQ.push(mid);
                    mid = maxQ.top();
                    maxQ.pop();
                } else if (maxQ.size() < minQ.size()) {
                    maxQ.push(mid);
                    mid = minQ.top();
                    minQ.pop();
                }
                answer.push_back(mid);
            }
        }
        cout << answer.size() << "\n";
        for (const int d: answer) cout << d << " ";
        cout << "\n";
    }
    return 0;
}