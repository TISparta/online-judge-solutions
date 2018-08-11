/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags : Game Theory
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int N_BITS = 16, P_POSITION = 0, N_POSITION = 1;

int D, N, M, T;
unordered_set <string> dict;
unordered_map <int, int> memo;
char letter[N_BITS + 1];
string word;

string getWord(int mask) {
    string ret = "";
    while (mask) {
        ret += letter[__builtin_ctz(mask & -mask)];
        mask = mask bitand (mask - 1);
    }
    return ret;
}

int findPosition(int mask) {
    if (memo.find(mask) != memo.end()) return memo[mask];
    if (mask == 0) return P_POSITION;
    int pib_mask = mask, ret = P_POSITION;
    while (pib_mask and ret != N_POSITION) {
        if(dict.find(getWord(pib_mask)) != dict.end())
            ret |= not findPosition(mask xor pib_mask);
        pib_mask = (pib_mask - 1) bitand mask;
    }
    return memo[mask] = ret;
}

void readMatrix() {
    string w = "";
    for (int row = 0; row < N; row++) {
        char ch;
        while ((ch = getchar()) != '\n') w += ch;
    }
    sort(w.begin(), w.end());
    for (int id = 0; id < N * M; id++) letter[id] = w[id];
}

void readDict() {
    cin >> D;
    while (D--) {
        cin >> word;
        sort(word.begin(), word.end());
        dict.insert(word);
    }
}

void clear() {
    memo.clear();
}

int main() {
    readDict();
    cin >> N >> M >> T;
    cin.ignore();
    while (T--) {
        clear();
        readMatrix();
        puts(findPosition((1 << (N * M)) - 1) == P_POSITION ? "Bob" : "Alice");
    }
    return (0);
}
