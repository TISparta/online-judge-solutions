/**
 * > Author : TISparta
 * > Date : 03-05-18
 * > Tag : Mo algorithm
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5, MAX_Q = 1e5, OFFSET = 10;

int N, Q, BLOCK_SIZE, arr[MAX_N + OFFSET], ans[MAX_N + OFFSET], ct[MAX_N + OFFSET];
string word;
unordered_map <string, int> order;

struct Query {
    int l, r, order, id;
    Query() {};
    Query(int l_, int r_, int order_, int id_): l(l_), r(r_), order(order_), id(id_) {}
    bool operator < (const Query& other) const {
        int block_x = this -> l / BLOCK_SIZE;
        int block_y = other.l / BLOCK_SIZE;
        if (block_x != block_y) return block_x < block_y;
        return this -> r < other.r;
    }
}query[MAX_Q + OFFSET];

void print() {
    for (int i = 0; i < Q; i++) printf("%d\n", ans[i]);
}

inline void add(int pos) {
    ct[arr[pos]]++;
}

inline void remove(int pos) {
    ct[arr[pos]]--;
}

void MoAlgorithm() {
    BLOCK_SIZE = sqrt(N);
    sort(query, query + Q);
    int mo_left = 0, mo_right = -1;
    for (int i = 0; i < Q; i++) {
        while (mo_right < query[i].r) add(++mo_right);
        while (mo_right > query[i].r) remove(mo_right--);
        while (mo_left < query[i].l) remove(mo_left++);
        while (mo_left > query[i].l) add(--mo_left);
        ans[query[i].id] = ct[query[i].order];
    }
}

void readInput() {
    cin >> N;
    long long hash_;
    for (int i = 0, ct = 0; i < N; i++) {
        cin >> word;
        if (order[word] == 0) order[word] = ++ct;
        arr[i] = order[word];
    }
    scanf("%d", &Q);
    for (int i = 0, order_, l, r; i < Q; i++) {
        cin >> l >> r >> word;
        order_ = order[word];
        query[i] = Query(--l, --r, order_, i);
    }
}

int main() {
    readInput();
    MoAlgorithm();
    print();
    return (0);
}
