#include <bits/stdc++.h>

#define WIN        1
#define FAIL      -1
#define UNVISITED -2

using namespace std;

const int MAX_N = 1010;

int8_t memo[MAX_N][MAX_N][2];

int minVal(int, int);
int maxVal(int, int);

int minVal(int limit, int n) {
    if (n == 0) return WIN;
    if (memo[limit][n][0] != UNVISITED) return memo[limit][n][0];
    int ret = WIN;
    for (int k = 1; k <= limit and ret != FAIL; k++)
        ret = min(ret, maxVal(min(2 * k, n - k), n - k));
    return memo[limit][n][0] = ret;
}

int maxVal(int limit, int n) {
    if (n == 0) return FAIL;
    if (memo[limit][n][1] != UNVISITED) return memo[limit][n][1];
    int ret = FAIL;
    for (int k = 1; k <= limit and ret != WIN; k++)
        ret = max(ret, minVal(min(2 * k, n - k), n - k));
    return memo[limit][n][1] = ret;
}

bool minimax(int n) {
    return maxVal(n - 1, n) == WIN;
}

int main() {
    int n;
    memset(memo, UNVISITED, sizeof memo);
    while (scanf("%d", &n), n) puts(minimax(n) ? "Alicia" : "Roberto");
    return (0);
}