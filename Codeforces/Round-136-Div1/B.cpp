// Tags: Mo Algorithm
// Difficulty: 5.5
// Priority: 1
// Date: 28-02-2018

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5, MAX_Q = 1e5, OFFSET = 2;

int N, Q, BLOCK_SIZE, current_ans, arr[MAX_N + OFFSET], ans[MAX_Q + OFFSET];
unordered_map <int ,int> frec;

struct Query {
    int left, right, id;
    Query() {}
    Query(int left_, int right_, int id_): left(left_), right(right_), id(id_) {}
    bool operator < (const Query& other) const {
        int this_block = this -> left / BLOCK_SIZE;
        int other_block = other.left / BLOCK_SIZE;
        if (this_block != other_block) return this_block < other_block;
        return this -> right < other.right;
    }

}query[MAX_Q + OFFSET];

void printAnswer() {
    for (int i = 0; i < Q; i++) cout << ans[i] << endl;    
}

void add(const int& pos) {
    int& ret = frec[arr[pos]];
    if (ret == arr[pos] - 1) current_ans++;
    else if (ret == arr[pos]) current_ans--;
    ret++;
}

void remove(const int& pos) {
    int& ret = frec[arr[pos]];
    if (ret == arr[pos]) current_ans--;
    if (ret == arr[pos] + 1) current_ans++;
    ret--;
}

void MoAlgorithm() {
    BLOCK_SIZE = sqrt(N);
    sort(query, query + Q);
    int mo_left = 0, mo_right = -1;
    for (int i = 0; i < Q; i++) {
        while (mo_right < query[i].right) add(++mo_right);
        while (mo_right > query[i].right) remove(mo_right--);
        while (mo_left < query[i].left) remove(mo_left++);
        while (mo_left > query[i].left) add(--mo_left);
        ans[query[i].id] = current_ans;
    }
}

void readInput() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0, left_, right_; i < Q; i++) {
        cin >> left_ >> right_;
        query[i] = Query(--left_, --right_, i);
    }
}

inline void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
}

int main() {
    fastIO();
    readInput();
    MoAlgorithm();
    printAnswer();
    return (0);
}
