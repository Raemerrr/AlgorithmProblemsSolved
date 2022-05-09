#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;
int N, M, target, answer;
deque<int> nDeque, mDeque;
deque<ULL> nSum, mSum;

void calc(deque<ULL> &sum, deque<int> &dq, const int Size) {
    for (int i = 0; i < Size; i++) {
        int loopSize = (i == 0) ? Size : Size - 1;
        deque<ULL> tempSum(loopSize, 0);
        for (int j = 0; j < loopSize; j++) {
            tempSum[j] = (j == 0) ? dq[j] : tempSum[j - 1] + dq[j];
            if (tempSum[j] == target) answer++;
        }
        dq.push_back(dq.front());
        dq.pop_front();
        sum.insert(sum.begin(), tempSum.begin(), tempSum.end());
    }
    sort(sum.begin(), sum.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> target >> N >> M;
    nDeque.assign(N, 0);
    mDeque.assign(M, 0);
    for (int i = 0; i < N; i++) cin >> nDeque[i];
    for (int i = 0; i < M; i++) cin >> mDeque[i];
    calc(nSum, nDeque, N);
    calc(mSum, mDeque, M);
    deque<ULL> uniqueNSum = nSum;
    uniqueNSum.erase(unique(uniqueNSum.begin(), uniqueNSum.end()), uniqueNSum.end());
    for (const ULL &d: uniqueNSum) {
        if (d > target) break;
        auto[nHi, nLo] = equal_range(nSum.begin(), nSum.end(), d);
        int nCnt = nHi - nLo;
        auto[mHi, mLo] = equal_range(mSum.begin(), mSum.end(), target - d);
        int mCnt = mHi - mLo;
        answer += nCnt * mCnt;
    }
    cout << answer << "\n";
    return 0;
}