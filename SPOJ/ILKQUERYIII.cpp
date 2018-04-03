/**
 * > Author : TISparta
 * > Date : 03-04-18
 * > Tag : Wavelet Tree
 * > Difficulty : 7 / 10
 */

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()

using namespace std;

typedef vector <int>::iterator iter;

struct WaveletTree {
    WaveletTree *left = 0, *right = 0;
    int lo, hi, mid;
    vector <int> ct, left_idx, right_idx, left_arr, right_arr;

    WaveletTree() {}

    WaveletTree(vector <int>& arr, vector <int>& idx, int lo_, int hi_) {
        lo = lo_, hi = hi_;
        mid = (lo + hi) >> 1;
        ct.reserve(arr.size() + 1);
        ct.emplace_back(0);
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= mid) {
                left_arr.push_back(arr[i]);
                left_idx.push_back(idx[i]);
            }
            else {
                right_arr.push_back(arr[i]);
                right_idx.push_back(idx[i]);
            }
            ct.push_back(ct.back() + (arr[i] <= mid));
        }
        if (lo == hi) return;
        left = new WaveletTree(left_arr, left_idx, lo, mid);
        right = new WaveletTree(right_arr, right_idx, mid + 1, hi);
    };

    ~WaveletTree() {
        delete left;
        delete right;
    }

    int kth(int a, int b, int k) {
        if (lo == hi) return lo;
        int inLeft = ct[b] - ct[a - 1];
        if (k <= inLeft) return left -> kth(ct[a], ct[b], k);
        return right -> kth(a - ct[a], b - ct[b], k - inLeft);
    }

    int kthPos(int val, int k) {
        if (lo == hi) {
            return k - 1 < left_idx.size() ? left_idx[k - 1] : -1;
        }
        if (val <= mid) return left ? left -> kthPos(val, k) : -1;
        return right ? right -> kthPos(val, k) : -1;
    }

    void swap(const int& val_1, const int& val_2, int pos) {
        if (val_1 <= mid and val_2 <= mid) {
            if (left) left -> swap(val_1, val_2, ct[pos]);
        }
        if (val_1 > mid and val_2 > mid) {
            if (right) right -> swap(val_1, val_2, pos - ct[pos]);
        }
        if (val_1 <= mid and val_2 > mid) {
            ct[pos]--;
        }
        if (val_1 > mid and val_2 <= mid) {
            ct[pos]++;
        }
    }

    void updateLeafIdx(const int& val, int pos, const int& inc) {
        if (lo == hi) {
            if (0 <= pos - 1) {
                left_idx[pos - 1] += inc;
                if (0 <= pos - 2 and left_idx[pos - 2] > left_idx[pos - 1]) {
                    std::swap(left_idx[pos - 2], left_idx[pos - 1]);
                }
                if (pos < left_idx.size() and left_idx[pos - 1] > left_idx[pos]) {
                    std::swap(left_idx[pos - 1], left_idx[pos]);
                }
            }
            return;
        }
        if (val <= mid and left) left -> updateLeafIdx(val, ct[pos], inc);
        else if (right) right -> updateLeafIdx(val, pos - ct[pos], inc);
    }

};

int N, Q, sigma;
vector <int> arr, A, idx;
unordered_map <int, int> mp, ct;
WaveletTree *tree;

void compress() {
    sort(all(A));
    mp[A[0]] = ++sigma;
    for (int i = 1; i < N; i++) {
        if (A[i] != A[i - 1]) sigma++;
        mp[A[i]] = sigma;
    }
    for (int i = 0; i < N; i++) {
        arr[i] = mp[arr[i]];
        ct[arr[i]]++;
    }

}

void read() {
    scanf("%d %d", &N, &Q);
    arr.resize(N);
    A.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        A[i] = arr[i];
    }
}

int main() {
    read();
    compress();
    idx.resize(N);
    iota(all(idx), 0);
    tree = new WaveletTree(arr, idx, 1, sigma);
    while (Q--) {
        int q, k, i, l, d;
        scanf("%d", &q);
        if (q == 0) {
            scanf("%d %d %d", &i, &l, &k);
            d = tree -> kth(1, i + 1, k);
            printf("%d\n", tree -> kthPos(d, l));
        }
        else {
            scanf("%d", &i);
            if (i + 1 != N) {
                tree -> updateLeafIdx(arr[i], i + 1, 1);
                tree -> updateLeafIdx(arr[i + 1], i + 2, -1);
                tree -> swap(arr[i], arr[i + 1], i + 1);
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    delete tree;
    return (0);
}
