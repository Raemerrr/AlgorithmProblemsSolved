#include <iostream>

using namespace std;

int N, J, answer;

class Bucket {
public:
    int leftPos;
    int rightPos;

    Bucket() {
        this->leftPos = 0;
        this->rightPos = 0;
    }

    int move(int pos) {
        int result = 0;
        if (leftPos <= pos && pos <= rightPos) return result;
        if (pos < leftPos) {
            while (0 < leftPos && pos < leftPos) {
                result++;
                leftPos--;
                rightPos--;
            }
        } else {
            while (rightPos < N && rightPos < pos) {
                result++;
                leftPos++;
                rightPos++;
            }
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Bucket bucket;
    cin >> N >> bucket.rightPos >> J;
    bucket.rightPos--;
    for (int i = 0; i < J; i++) {
        int pos = 0;
        cin >> pos;
        pos--;
        answer += bucket.move(pos);
    }
    cout << answer << "\n";
    return 0;
}