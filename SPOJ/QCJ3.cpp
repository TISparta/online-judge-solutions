/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags : Game Theory
 * > Difficulty : 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int T, N, n_piles, nim_sum;

int main() {
    scanf("%d", &T);
    while (T--) {
        nim_sum = 0;
        scanf ("%d", &N);
        for (int pile = 1; pile <= N; pile++) {
            scanf("%d", &n_piles);
            if (n_piles & 1) nim_sum ^= pile;
        }
        puts(nim_sum == 0 ? "Hanks Wins" : "Tom Wins");
    }
    return (0);
}
