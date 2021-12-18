#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case = 0;
    cin >> test_case;
    while (test_case--) {
        int sum = 0, answer = 101;
        vector<int> v(7, 0);
        for (int i = 0; i < 7; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for (const int d: v) {
            if (d % 2 == 0) {
                sum += d;
                answer = min(answer, d);
            }
        }
        cout << sum << " " << answer << "\n";
    }
    return 0;
}