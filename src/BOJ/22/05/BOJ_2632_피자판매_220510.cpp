#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;
int K, N, M, answer;
deque<int> nQ, mQ;
deque<ULL> nSum, mSum;

void calc(deque<ULL> &sum, deque<int> &dq) {
    for (int i = 0, size = dq.size(); i < size; i++) {
        int loopSize = (i == 0) ? size : size - 1;
        deque<ULL> temp(loopSize, 0);
        for (int j = 0; j < loopSize; j++) {
            temp[j] = (j == 0) ? dq[j] : temp[j - 1] + dq[j];
            if (temp[j] == K) answer++;
        }
        dq.push_back(dq.front());
        dq.pop_front();
        sum.insert(sum.begin(), temp.begin(), temp.end());
    }
    sort(sum.begin(), sum.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> K >> N >> M;
    nQ.assign(N, 0);
    mQ.assign(M, 0);
    for (int i = 0; i < N; i++) cin >> nQ[i];
    for (int i = 0; i < M; i++) cin >> mQ[i];
    calc(nSum, nQ);
    calc(mSum, mQ);
    deque<ULL> uniqueQ = nSum;
    uniqueQ.erase(unique(uniqueQ.begin(), uniqueQ.end()), uniqueQ.end());
    for (const int d: uniqueQ) {
        auto[nHi, nLo] = equal_range(nSum.begin(), nSum.end(), d);
        int nCnt = nHi - nLo;
        auto[mHi, mLo] = equal_range(mSum.begin(), mSum.end(), K - d);
        int mCnt = mHi - mLo;
        answer += nCnt * mCnt;
    }
    cout << answer << "\n";
    return 0;
}