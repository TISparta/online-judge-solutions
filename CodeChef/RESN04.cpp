/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags : Game Theory
 * > Difficulty : 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int T, N, pile, turns;

int main() {
    scanf("%d", &T);
    while (T--) {
        turns = 0;
        scanf("%d", &N);
        for (int id = 1; id <= N; id++) {
            scanf("%d", &pile);
            turns += pile / id;
        }
        puts(turns & 1 ? "ALICE" : "BOB");
    }
    return (0);
}
