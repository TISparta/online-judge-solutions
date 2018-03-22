#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 80;

char plaintext[MAX_N], ciphertext[MAX_N];
int n, k, plaincode[MAX_N], ciphercode[MAX_N];

inline int map_ch(char ch) {
    if (ch == '_') return 0;
    if (ch == '.') return 27;
    return ch - 'a' + 1;
}

inline char map_int(int num) {
    if (num == 0) return '_';
    if (num == 27) return '.';
    return 'a' + num - 1;
}

void decrypt() {
    n = strlen(ciphertext);
    for (int i = 0; i < n; i++) ciphercode[i] = map_ch(ciphertext[i]);
    for (int i = 0; i < n; i++) plaincode[k * i % n] = ( ciphercode[i] + i ) % 28;
    for (int i = 0; i < n; i++) plaintext[i] = map_int(plaincode[i]);
    for (int i = 0; i < n; i++) putchar(plaintext[i]); putchar('\n');
}

int main() {
    while (scanf("%d %s", &k, ciphertext), k) decrypt();
    return(0);
}