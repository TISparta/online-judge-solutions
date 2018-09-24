/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags: SQRT Decomposition
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5, OFFSET = 2;

int N, Q, BLOCK_SIZE, arr[MAX_N + OFFSET];
vector <vector <int>> chunks;
char op;

void processQuery() {
    getchar();
    scanf("%c", &op);
    if (op == 'M') {
        int pos, c_pos, new_val, id;
        scanf("%d %d", &pos, &new_val);
        pos--;
        id = pos / BLOCK_SIZE;
        c_pos = find(chunks[id].begin(), chunks[id].end(), arr[pos]) - chunks[id].begin();
        chunks[id][c_pos] = new_val;
        arr[pos] = new_val;
        sort(chunks[id].begin(), chunks[id].end());
    }
    else {
        int L, R, X, id, sum = 0;
        scanf("%d %d %d", &L, &R, &X);
        L--, R--;
        while (L <= R and L % BLOCK_SIZE != 0) {
            sum += arr[L] <= X;
            L++;
        }
        if (L % BLOCK_SIZE == 0) {
            id = L / BLOCK_SIZE;
            while (L + BLOCK_SIZE <= R) {
                sum += upper_bound(chunks[id].begin(), chunks[id].end(), X) - chunks[id].begin();
                L += BLOCK_SIZE;
                id++;
            }
        }
        while (L <= R) {
            sum += arr[L] <= X;
            L++;
        }
        printf("%d\n", sum);
    }
}

void readArray() {
    BLOCK_SIZE = sqrt(N);
    for (int i = 0, id = 0; i < N; id++) {
        chunks.push_back({});
        for (int j = i; j < N and j < i + BLOCK_SIZE; j++) {
            scanf("%d", arr + j);
            chunks[id].push_back(arr[j]);
        }
        sort(chunks[id].begin(), chunks[id].end());
        i += BLOCK_SIZE;
    }
}

int main() {
    scanf("%d %d", &N, &Q);
    readArray();
    while (Q--) processQuery();
    return (0);
}
