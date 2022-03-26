#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case = 0;
    cin >> test_case;
    while (test_case--) {
        int num = 0, two = 2, five = 5, twoCnt = 0, fiveCnt = 0;
        cin >> num;
        for (int j = two; j <= num; j *= two) twoCnt += (num / j);
        for (int j = five; j <= num; j *= five) fiveCnt += (num / j);
        cout << min(fiveCnt, twoCnt) << "\n";
    }
    return 0;
}