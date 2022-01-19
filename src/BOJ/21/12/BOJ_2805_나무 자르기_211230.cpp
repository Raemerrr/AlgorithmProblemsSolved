#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

int N, M, Left, Right, answer;
vector<int> v;

ULL cutting(const ULL h) {
    ULL sum = 0;
    for (const int d: v) {
        int temp = d - h;
        if (temp > 0) sum += temp;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    v.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        Right = max(Right, v[i]);
    }
    while (Left <= Right) {
        int mid = (Left + Right) / 2;
        ULL sum = cutting(mid);
        if (sum < M) {
            Right = mid - 1;
        } else {
            answer = max(answer, mid);
            Left = mid + 1;
        }
    }
    cout << answer << "\n";
    return 0;
}