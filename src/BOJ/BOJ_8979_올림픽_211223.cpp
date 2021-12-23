#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Score {
    int id;
    int gold;
    int silver;
    int bronze;

    Score(int id, int gold, int silver, int bronze) : id(id), gold(gold), silver(silver), bronze(bronze) {}

    bool operator<(const Score &other) const {
        if (this->gold == other.gold) {
            if (this->silver == other.silver) {
                return this->bronze < other.bronze;
            }
            return this->silver < other.silver;
        }
        return this->gold < other.gold;
    }

    bool operator!=(const Score &other) const {
        if (this->gold == other.gold && this->silver == other.silver && this->bronze == other.bronze) return false;
        return true;
    }
};

int N, K;
vector<Score> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    v.assign(N, Score(0, 0, 0, 0));
    for (int i = 0; i < N; i++) {
        cin >> v[i].id >> v[i].gold >> v[i].silver >> v[i].bronze;
    }
    sort(v.begin(), v.end());
    Score prev(-1, -1, -1, -1);
    int rank = 1;
    while (!v.empty()) {
        Score back = v.back();
        v.pop_back();
        if (prev != back) {
            rank = N - v.size();
            prev = back;
        }
        if (back.id == K) {
            break;
        }
    }
    cout << rank << "\n";
    return 0;
}