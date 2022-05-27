#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer;
vector<int> v, store;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N + 2, 0);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    store.push_back(0);
    for (int i = 1; i <= N + 1; i++) {
        while (!store.empty() && v[store.back()] > v[i]) {
            int index = store.back();
            store.pop_back();
            answer = max(answer, (v[index] * (i - store.back() - 1)));
        }
        store.push_back(i);
    }
    cout << answer << "\n";
    return 0;
}