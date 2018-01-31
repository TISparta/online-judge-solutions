#include <bits/stdc++.h>

using namespace std;

namespace Pattern {
    int minVal(int, int);
    int maxVal(int, int);
    int minimax(int);
    void getAnswers(int);
}

namespace Pattern {

    const int WIN  =  1;
    const int FAIL = -1;

    int minVal(int _max, int _min) {
        if (_max == 1 and _min == 1) return WIN;
        int ret = WIN;
        for (int it = 1; 2 * it <= _max and ret != FAIL; it++)
            ret = min(ret, maxVal(max(it, _max - it), min(it, _max - it)));
        return ret;
    }

    int maxVal(int _max, int _min) {
        if (_max == 1 and _min == 1) return FAIL;
        int ret = FAIL;
        for (int it = 1; 2 * it <= _max and ret != WIN; it++)
            ret = max(ret, minVal(max(it, _max - it), min(it, _max - it)));
        return ret;
    }

    int minimax(int k) {
        return maxVal(k, 1) == WIN;
    }

    void getAnswers(int limit) {
        for (int k = 2; k <= limit; k++)
            printf("%3d : %s\n", k, minimax(k) ? "Alice" : "Bob");
    }

}

const int Alice = 0;
const int Bob   = 1;

int n;
map <int, int> winner;

void fillBobPositions() {
    for (long long k = 3; k <= 1e9; k = k * 2 + 1) winner[k] = Bob;
}


int main() {
    //Pattern::getAnswers(35);
    fillBobPositions();
    while (scanf("%d", &n), n) puts(winner[n] == Alice ? "Alice" : "Bob");
    return (0);
}