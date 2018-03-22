#include <bits/stdc++.h>

using namespace std;

const int LEN = 35;

int tc, n, ans;
char P[LEN], line[LEN + 5];

inline void print() {
    printf("Case %d: %d\n", ++tc, ans);
}

bool check(int mask, int sz) {
    int power = (1 << sz) - 1;
    int s1 = mask bitand power;
    mask >>= sz;
    int s2 = mask bitand power;
    mask >>= sz;
    int s3 = mask bitand power;
    return (s1 == s2 and s2 == s3);
}

bool isValid(int mask, int len) {
    ++len;
    for (int sz = 1; sz * 3 <= len; sz++)
        if (check(mask, sz)) return false;
    return true;
}

inline int mark(int mask, int bit) {
    return ((mask << 1) bitor bit);
}

void backtrack(int id = 0, int mask = 0) {
    if (id == n) {
        ans++;
        return;
    }
    int mask_0 = mark(mask, 0);
    int mask_1 = mark(mask, 1);
    if (P[id] == '*') {
        P[id] = '0';
        if (isValid(mask_0, id)) backtrack(id + 1, mask_0);
        P[id] = '1';
        if (isValid(mask_1, id)) backtrack(id + 1, mask_1);
        P[id] = '*';
    }
    else if (P[id] == '0') {
        if (isValid(mask_0, id)) backtrack(id + 1, mask_0);
    }
    else {
        if (isValid(mask_1, id)) backtrack(id + 1, mask_1);
    }
}

inline void init() {
    ans = 0;
}

bool read() {
    init();
    scanf("%d", &n);
    if (n == 0) return false;
    scanf("%s\n", P);
    return true;
}

int main() {
    while (read()) {
        backtrack();
        print();
    }
    return (0);
}