#include <bits/stdc++.h>

using namespace std;

long long n, num;
bool stan_turn;

int main() {
    while (~scanf("%lld", &n)) {
        stan_turn = true, num = 1;
        while (num < n) {
            if (stan_turn) num *= 9;
            else num *= 2;
            stan_turn ^= 1;
        }
        puts(stan_turn ? "Ollie wins." : "Stan wins.");
    }
    return (0);
}