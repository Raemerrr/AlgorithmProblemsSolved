#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v, temp,answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, 0);
    answer.assign(N, -1);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        while (!temp.empty() && v[temp.back()] < v[i]){
            answer[temp.back()] = v[i];
            temp.pop_back();
        }
        temp.push_back(i);
    }
    for (const int d: answer) cout << d << " ";
    cout << "\n";
    return 0;
}