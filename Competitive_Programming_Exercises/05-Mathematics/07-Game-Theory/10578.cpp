#include <bits/stdc++.h>

#define WIN   1
#define FAIL -1

using namespace std;

const int SIZE = 100, MAX_CARD = 10;

char moves[SIZE];
int sum, ct[MAX_CARD];

int minVal();
int maxVal();

int minVal() {
    int res = WIN;
    for (int card = 1; card <= 6 and res != FAIL; card++)
        if (ct[card]) {
            sum += card, ct[card]--;
            res = min(res, sum > 31 ? WIN : maxVal());
            sum -= card, ct[card]++;
        }
    return res;
}

int maxVal() {
    int res = FAIL;
    for (int card = 1; card <= 6 and res != WIN; card++)
        if (ct[card]) {
            sum += card, ct[card]--;
            res = max(res, sum > 31 ? FAIL : minVal());
            sum -= card, ct[card]++;
        }
    return res;
}

int minimax(bool a_turn) {
    sum = 0;
    for (int id = 0; moves[id]; id++) sum += moves[id] - '0', ct[moves[id] - '0']--;
    int ret = (a_turn) ? maxVal() : minVal();
    return ret;
}

void init() {
    for (int i = 0; i < MAX_CARD; i++) ct[i] = 4;
}

int main() {
    while (~scanf("%s\n", moves)) {
        init();
        printf("%s %c\n", moves, minimax((strlen(moves) & 1) == 0) == WIN ? 'A' : 'B');
    }
    return (0);
}