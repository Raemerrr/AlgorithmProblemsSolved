#include <iostream>

using namespace std;

typedef long long LL;

int num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> num) {
        int cnt = 1;
        LL K = 1;
        while (true) {
            if (K % num == 0) {
                cout << cnt << "\n";
                break;
            }
            // 나누어 떨어지냐? 아니냐? 중요.
            // 즉 num=3 일때, 11->111 가는 과정에서 110=90+20=20(mod 3)
            K %= num;
            K = (K * 10) + 1;
            cnt++;
        }
    }
    return 0;
}