#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        int Cur = v[i];
        int Left = 0, Right = N - 1;
        while (Left < Right) {
            int Sum = v[Left] + v[Right];
            if (Sum < Cur) Left++;
            else if (Sum > Cur) Right--;
            else /*if (Sum == Cur)*/ {
                if (Left != i && Right != i) {
                    answer++;
                    break;
                } else if (Left == i) Left++;
                else if (Right == i) Right--;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}