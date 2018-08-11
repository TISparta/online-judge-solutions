/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags : Game Theory
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int N, T, winning_pile, winning_move;
vector <int> piles, affect;

void print() {
    puts(~winning_move ? "Mary wins" : "Johnny wins");
    if (~winning_move) printf("Move %d to %d\n", winning_pile, winning_move);
    putchar('\n');
}

int nimsum() {
    int sum = 0;
    for (int i = N; i > 0; i -= 2) {
        sum ^= piles[i] - piles[i - 1] - 1;
        affect[i] = +1;
    }
    for (int i = N - 1; i >= 0; i -= 2) affect[i] = -1;
    return sum;
}

void solve() {
    int sum = nimsum(), id = 1;
    for (int it = 1, current = 1; it <= N and winning_move == -1; it++) {
        if (affect[it] == 1) sum ^= piles[it] - piles[it - 1] - 1;
        else sum ^= piles[it + 1] - piles[it] - 1;
        for (int move = current; move < piles[it] and winning_move == -1; move++) {
            if (affect[it] == 1) sum ^= move - piles[it - 1] - 1;
            else sum ^= piles[it + 1] - move - 1;
            if (sum == 0) winning_pile = piles[it], winning_move = move;
            if (affect[it] == 1) sum ^= move - piles[it - 1] - 1;
            else sum ^= piles[it + 1] - move - 1;

        }
        if (affect[it] == 1) sum ^= piles[it] - piles[it - 1] - 1;
        else sum ^= piles[it + 1] - piles[it] - 1;
        current = piles[it] + 1;
    }
}

void readCase() {
    scanf("%d", &N);
    piles = {0};
    affect = {0};
    for (int it = 0, pile; it < N; it++) scanf("%d", &pile), piles.push_back(pile), affect.push_back(0);
}

void clear() {
    winning_pile = winning_move = -1;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        clear();
        readCase();
        solve();
        print();
    }
    return (0);
}
