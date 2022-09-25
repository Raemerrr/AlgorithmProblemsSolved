#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int aSize, bSize;
vector<int> a, b, answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> aSize >> bSize;
    a.assign(aSize, 0);
    b.assign(bSize, 0);
    for (int i = 0; i < aSize; i++) cin >> a[i];
    for (int i = 0; i < bSize; i++) cin >> b[i];
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    for (const int d: a) {
        auto it = lower_bound(b.begin(), b.end(), d);
        if (it == b.end() || d != *(it)) {
            answer.push_back(d);
        }
    }
    cout << answer.size() << "\n";
    for (const int d: answer) cout << d << " ";
    cout << "\n";
    return 0;
}