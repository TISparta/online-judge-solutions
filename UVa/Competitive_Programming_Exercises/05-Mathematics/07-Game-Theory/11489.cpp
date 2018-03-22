#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1010;

int tc;
char N[SIZE];

bool doesSwin() {
    bool S_turn = true;
    int sum = 0;
    for (int i = 0; N[i]; i++) sum += N[i] - '0';
    while (true) {
        bool possible = false;
        for (int i = 0; N[i]; i++) {
            if (N[i] and (N[i] - '0') % 3 == sum % 3) {
                S_turn = !S_turn;
                sum -= N[i] - '0';
                N[i] = 0;
                possible = true;
            }
        }
        if (not possible) break;
    }
    return S_turn == false;
}

int main() {
    scanf("%d\n", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%s\n", N);
        printf("Case %d: %c\n", t, doesSwin() ? 'S' : 'T');
    }
    return (0);
}