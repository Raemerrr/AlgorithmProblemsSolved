#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> v;

int dfs(const int cur){
    int result = 0;
    int weight = v[cur].size();
    vector<int> temp;
    for (const int _next : v[cur]) {
        temp.push_back(dfs(_next));
    }
    sort(temp.begin(), temp.end());
    for (const int d: temp) {
        result = max(result, d + weight--);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, vector<int>());
    for (int i = 0; i < N; i++) {
        int num = 0;
        cin >> num;
        if (num == -1) continue;
        v[num].push_back(i);
    }
    cout << dfs(0) << "\n";
    return 0;
}