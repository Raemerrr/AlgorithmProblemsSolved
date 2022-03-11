#include <iostream>

using namespace std;

typedef unsigned long long ULL;
ULL A, B, C;

ULL power(ULL A, ULL B, ULL MOD) {
    if (B == 0) return 1;
    if (B == 1) return A % MOD;
    if (B % 2 != 0) return power(A, B - 1, MOD) * A % MOD;
    else return power(A * A % MOD, B / 2, MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> A >> B >> C;
    cout << power(A, B, C) << "\n";
    return 0;
}