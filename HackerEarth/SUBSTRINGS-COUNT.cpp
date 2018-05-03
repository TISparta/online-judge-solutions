/**
 * > Author : TISparta
 * > Date : 03-05-18
 * > Tag : Mo algorithm
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
     
const int MAX_N = 1e4, MAX_Q = 5e5, MAX_LEN = 10, OFFSET = 10;
     
int N, Q, BLOCK_SIZE, arr[MAX_N + OFFSET], ans[MAX_Q + OFFSET];
char word[MAX_LEN + OFFSET];
vector <ll> substrings[MAX_N + OFFSET];
unordered_map <ll, int> order, cnt;
     
struct Query {
    int left, right, idx;
    ll hash;
    Query() {};
    Query(int left_, int right_, ll hash_, int idx_):
        left(left_), right(right_), hash(hash_), idx(idx_) {}
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
     
ll getHash() {
    ll ret = 0;
    for (int i = 0; word[i]; i++) ret = ret * 27 + (word[i] - 'a' + 1);
    return ret;
}
     
void add(int pos) {
    for (const ll& si : substrings[arr[pos]]) cnt[si]++;
}
     
void reduce(int pos) {
    for (const ll& si : substrings[arr[pos]]) cnt[si]--;
}
     
void MoAlgorithm() {
    BLOCK_SIZE = sqrt(N);
    sort(query, query + Q);
    int mo_left = 0, mo_right = -1;
    for (int i = 0; i < Q; i++) {
        while (mo_right < query[i].right) add(++mo_right);
        while (mo_right > query[i].right) reduce(mo_right--);
        while (mo_left < query[i].left) reduce(mo_left++);
        while (mo_left > query[i].left) add(--mo_left);
        ans[query[i].idx] = cnt[query[i].hash];
    }
}
     
void constructSubstring(const int& id, const int& len) {
    set <ll> vis;
    ll hash_;
    for (int it_1 = 0; it_1 < len; it_1++) {
        hash_ = 0;
        for (int it_2 = it_1; it_2 < len; it_2++) {
            hash_ = hash_ * 27 + (word[it_2] - 'a' + 1);
            if (vis.find(hash_) == vis.end()) substrings[id].emplace_back(hash_);
            vis.insert(hash_);
        }
    }
}
     
void readInput() {
    scanf("%d\n", &N);
    ll hash_;
    for (int i = 0, id = 0, len; i < N; i++) {
        scanf("%s\n", word);
        len = strlen(word);
        hash_ = getHash();
        if (order[hash_] == 0) {
            order[hash_] = ++id;
            constructSubstring(id, len);
        }
        arr[i] = order[hash_];
    }
    scanf("%d", &Q);
    for (int i = 0, left_, right_; i < Q; i++) {
        scanf("%d %d %s\n", &left_, &right_, word);
        query[i] = Query(--left_, --right_, getHash(), i);
    }
}
     
int main() {
    readInput();
    MoAlgorithm();
    print();
    return (0);
}
