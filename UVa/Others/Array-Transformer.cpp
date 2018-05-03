#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e5, OFFSET = 2;

int N, Q, BLOCK_SIZE;
long long u, arr[MAX_N + OFFSET];
vector <vector <long long>> chunks;

inline void printArray() {
    for (int i = 0; i < N; i++) cout << arr[i] << endl;
}

void processQuery() {
    int L, R, v, p;
    cin >> L >> R >> v >> p;
    L--, R--, p--;
    int den = R - L + 1, id, cp;
    long long k = 0;
    while (L <= R and L % BLOCK_SIZE != 0) {
        k += arr[L] < v;
        L++;
    }
    if (L % BLOCK_SIZE == 0) {
        id = L / BLOCK_SIZE;
        while (L + BLOCK_SIZE <= R) {
            k += upper_bound(chunks[id].begin(), chunks[id].end(), v - 1) - chunks[id].begin();
            L += BLOCK_SIZE;
            id++;
        }
    }
    while (L <= R) {
        k += arr[L] < v;
        L++;
    }
    long long new_val = k * u / den;
    id = p / BLOCK_SIZE;
    cp = find(chunks[id].begin(), chunks[id].end(), arr[p]) - chunks[id].begin();
    chunks[id][cp] = new_val;
    arr[p] = new_val;
    sort(chunks[id].begin(), chunks[id].end());
}

void readArray() {
    cin >> N >> Q >> u;
    BLOCK_SIZE = sqrt(N);
    for (int i = 0, id = 0; i < N; id++) {
        chunks.push_back({});
        for (int j = i; j < N and j < i + BLOCK_SIZE; j++) {
            cin >> arr[j];
            chunks[id].push_back(arr[j]);
        }
        sort(chunks[id].begin(), chunks[id].end());
        i += BLOCK_SIZE;
    }
}

inline void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main() {
    fastIO();
    readArray();
    while (Q--) processQuery();
    printArray();
    return (0);
}
