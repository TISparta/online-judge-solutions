/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags : Game Theory
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int JHON = 1, BROTHER = 0;

int T, N;
vector <int> piles;

void makeOptimalMove() {

    int ones = 0, no_ones = 0, pos;
    for (int id = 0; id < piles.size(); id++) {
        if (piles[id] == 1) ones++;
        else no_ones++, pos = id;
    }
    if (no_ones == 1) {
        if (ones & 1) piles.erase(piles.begin() + pos);
        else piles[pos] = 1;
        return;
    }
    int nim_sum = 0;
    for (int pile : piles) nim_sum ^= pile;
    if (nim_sum == 0) {
        piles.erase(piles.begin());
        return;
    }
    for (int id = 0; id < piles.size(); id++) {
        nim_sum ^= piles[id];
        if (nim_sum < piles[id]) {
            piles[id] = nim_sum;
            if (piles[id] == 0) piles.erase(piles.begin() + id);
            return;
        }
        nim_sum ^= piles[id];
    }
}

bool misereNim() {

    bool turn = JHON;

    while (not piles.empty()) makeOptimalMove(), turn ^= 1;
    
    return turn == JHON;
}

int main() {
    int pile;
    scanf("%d", &T);
    while (T--) {
        piles.clear();
        scanf("%d", &N);
        for (int id = 0; id < N; id++) {
            scanf("%d", &pile);
            piles.push_back(pile);
        }
        puts(misereNim() ? "John" : "Brother");
    }
    return (0);
}
