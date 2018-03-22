#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 6, OFFSET = 5, MAX_EVEN = 10, MAX_ODD = 9;

int T, sum, ct[MAX_N + OFFSET];
bool zero, valid;

void backtracking(int num = 1, int s = 0) {
    if (num > MAX_N) {
        valid |= s == sum;
        return;
    }
    if (valid) return;
    if (ct[num]) {
        ct[num]--;
        backtracking(num, s + num);
        ct[num]++;
    }
    backtracking(num + 1, s);
}

void reduce() {
    for (int i = 1; i <= MAX_N; i++)
        ct[i] = (ct[i] & 1) ? min(ct[i], MAX_ODD) : min(ct[i], MAX_EVEN);
    sum = 0;
    for (int i = 1; i <= MAX_N; i++) sum += i * ct[i];
    sum >>= 1;
}

int getSum() {
    int S = 0;
    for (int i = 1; i <= MAX_N; i++) S += i * ct[i];
    return S;
}

int main() {
    while (true) {
        valid = false;
        zero = true;
        for (int i = 1; i <= MAX_N; i++) {
            scanf("%d", ct + i);
            zero &= ct[i] == 0;
        }
        if (zero) break;
        printf("Collection #%d:\n", ++T);
        if (getSum() & 1) {
            puts("Can't be divided.\n");
            continue;
        }
        reduce();
        backtracking();
        puts(valid ? "Can be divided.\n" : "Can't be divided.\n");
    }
    return (0);
}
