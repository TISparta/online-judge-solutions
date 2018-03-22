#include <bits/stdc++.h>

using namespace std;

const int MAX_L = 43;

int T, L, N, len, message;
char compressed[MAX_L];

void backtracking(int idx, int ones, int zeros) {
    if (ones < 0 or zeros < 0) return;
    if (idx == len) {
        if (ones == 0 and zeros == 0) message++;
        return;
    }
    if (compressed[idx] == '0') backtracking(idx + 1, ones, zeros - 1);
    else {
        long long num = 0;
        for (int i = idx; i < len; i++) {
            num = num * 2 + (compressed[i] - '0');
            if (num != 2 and (i + 1 == len or compressed[i + 1] == '0')) {
                if (num == 3) backtracking(i + 1, ones - 2, zeros);
                backtracking(i + 1, ones - num, zeros);
            }
        }
    }
}

int main() {
    while (scanf("%d %d\n", &L, &N) == 2 and L | N) {
        message = 0;
        scanf("%s\n", compressed);
        len = strlen(compressed);
        backtracking(0, N, L - N);
        printf("Case #%d: ", ++T);
        if (message == 0) puts("NO");
        else if (message == 1) puts("YES");
        else puts("NOT UNIQUE");
    }
    return (0);
}
