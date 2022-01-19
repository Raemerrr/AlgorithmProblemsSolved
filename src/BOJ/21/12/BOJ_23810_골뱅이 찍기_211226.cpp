#include <iostream>
#include <algorithm>

using namespace std;

int N;

void print(string str) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << str;
        }
        cout << "\n";
    }
}

int main() {
    cin >> N;
    print("@@@@@");
    print("@");
    print("@@@@@");
    print("@");
    print("@");
    return 0;
}