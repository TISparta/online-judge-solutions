/**
 * > Author : TISparta
 * > Date : 03-05-18
 * > Tags: Mo algorithm
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e4, MAX_Q = 2e5, MAX_AI = 1e6, OFFSET = 10;

int N, Q, BLOCK_SIZE, current_ans, arr[MAX_N + OFFSET], ans[MAX_Q + OFFSET], frec[MAX_AI + OFFSET];

struct Query {
    int left, right, idx;
    Query() {};
    Query(int left_, int right_, int idx_): left(left_), right(right_), idx(idx_) {}
    bool operator < (const Query& other) const {
        int this_block = this -> left / BLOCK_SIZE;
        int other_block = other.left / BLOCK_SIZE;
        if (this_block != other_block) return this_block < other_block;
        return this -> right < other.right;
    }
}query[MAX_Q + OFFSET];

void print() {
    for (int i = 0; i < Q; i++) printf("%d\n", ans[i]);
}

void add(const int& num) {
    if (0 == frec[num]) current_ans++;
    frec[num]++;
}

void remove(const int& num) {
    frec[num]--;
    if (0 == frec[num]) current_ans--;
}

void MoAlgorithm() {
    BLOCK_SIZE = sqrt(N);
    sort(query, query + Q);
    int mo_left = 0, mo_right = -1;
    for (int i = 0; i < Q; i++) {
        while (mo_right < query[i].right) add(arr[++mo_right]);
        while (mo_right > query[i].right) remove(arr[mo_right--]);
        while (mo_left < query[i].left) remove(arr[mo_left++]);
        while (mo_left > query[i].left) add(arr[--mo_left]);
        ans[query[i].idx] = current_ans;
    }
}

void readInput() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", arr + i);
    scanf("%d", &Q);
    for (int i = 0, left_, right_; i < Q; i++) {
        scanf("%d %d", &left_, &right_);
        query[i] = Query(--left_, --right_, i);
    }
}

int main() {
    readInput();
    MoAlgorithm();
    print();
    return (0);
}
