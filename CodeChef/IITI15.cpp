/**
 * > Author : TISparta
 * > Date : 03-05-18
 * > Tags : Mo algorithm, BIT
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e4, MAX_Q = 2e4, OFFSET = 10;

int N, Q, BLOCK_SIZE, arr[MAX_N + OFFSET], FT[MAX_N + OFFSET];
unordered_map <int, int> order;
long long number_inversions, ans[MAX_N + OFFSET];

struct Query {
    int left, right, idx;
    Query() {}
    Query(int left_, int right_, int idx_) : left(left_), right(right_), idx(idx_) {}
    bool operator < (const Query& other) const {
        int this_block = this -> left / BLOCK_SIZE;
        int other_block = other.left / BLOCK_SIZE;
        if (this_block != other_block) return this_block < other_block;
        return this -> right < other.right;
    }
}query[MAX_Q + OFFSET];

namespace FenwickTree {
    
    const int LIMIT = MAX_N + 1;

    void update(int pos, const int& var) {
        while (pos < LIMIT) {
            FT[pos] += var;
            pos += pos bitand -pos;
        }
    }

    long long getLeftSum(int pos) {
        long long sum = 0;
        while (pos) {
            sum += FT[pos];
            pos -= pos bitand -pos;
        }
        return sum;
    }

    long long getRightSum(int pos) {
        return getLeftSum(LIMIT - 1) - getLeftSum(pos);
    }

}

namespace Mo {

    inline void addRight(const int& pos) {
        FenwickTree::update(arr[pos], 1);
        number_inversions += FenwickTree::getRightSum(arr[pos]);
    }

    inline void addLeft(const int& pos) {
        FenwickTree::update(arr[pos], 1);
        number_inversions += FenwickTree::getLeftSum(arr[pos] - 1);
    }

    inline void reduceRight(const int& pos) {
        FenwickTree::update(arr[pos], -1);
        number_inversions -= FenwickTree::getRightSum(arr[pos]);
    }

    inline void reduceLeft(const int& pos) { 
        FenwickTree::update(arr[pos], -1);
        number_inversions -= FenwickTree::getLeftSum(arr[pos] - 1);
    }

};

void print() {
    for (int i = 0; i < Q; i++) cout << ans[i] << endl;
}

void MoAlgorithm() {
    BLOCK_SIZE = sqrt(N);
    sort(query, query + Q);
    int mo_left = 0, mo_right = -1;
    for (int i = 0; i < Q; i++) {
        while (mo_right < query[i].right) Mo::addRight(++mo_right);
        while (mo_right > query[i].right) Mo::reduceRight(mo_right--);
        while (mo_left < query[i].left) Mo::reduceLeft(mo_left++);
        while (mo_left > query[i].left) Mo::addLeft(--mo_left);
        ans[query[i].idx] = number_inversions;
    }
}

void read() {
    set <int> numbers;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        numbers.insert(arr[i]);
    }
    int id = 0;
    for (const int& num : numbers) order[num] = ++id;
    for (int i = 0; i < N; i++) arr[i] = order[arr[i]];
    cin >> Q;
    for (int i = 0, left_, right_; i < Q; i++) {
        cin >> left_ >> right_;
        query[i] = Query(--left_, --right_, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    read();
    MoAlgorithm();
    print();
    return (0);
}
