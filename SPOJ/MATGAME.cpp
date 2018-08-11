/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags : Game Theory
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 50;

int T, N, M, pile[MAX_M + 1], nim_sum, SGV;

int main() {
    scanf("%d", &T);
    while (T--) {
        nim_sum = 0;
        scanf("%d %d", &N, &M);
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) scanf("%d", &pile[col]);
            SGV = pile[M - 1];
            for (int col = M - 2; col >= 0; col--) SGV = pile[col] - (pile[col] <= SGV);
            nim_sum ^= SGV;
        }
        puts(nim_sum == 0 ? "SECOND" : "FIRST");
    }
    return (0);
}
