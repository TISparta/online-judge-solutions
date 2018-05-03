/**
 * > Author : TISparta
 * > Date : 04-04-18
 * > Tags : Wavelet Tree
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef vector <int>::iterator iter;

class WaveletTree {

public:
    WaveletTree *left = 0, *right = 0;
    int lo, hi, mid;
    vector <int> ct;

    WaveletTree(iter b, iter e, int lo_, int hi_) {
        lo = lo_, hi = hi_;
        mid = (lo + hi) >> 1;
        if (b >= e) return;
        ct.reserve(e - b + 1);
        ct.emplace_back(0);
        for (auto it = b; it != e; it++)
            ct.emplace_back(ct.back() + ((*it) <= mid));
        iter pivot = stable_partition(b, e, [=](const int& i) { return i <= mid; } );
        if (lo == hi) return;
        left = new WaveletTree(b, pivot, lo, mid);
        right = new WaveletTree(pivot, e, mid + 1, hi);
    };

    ~WaveletTree() {
        delete left;
        delete right;
    }

    int ocurrences(int a, int b, int k) {
        return ocurrences(b, k) - ocurrences(a - 1, k);
    }

    int kth(int a, int b, int k) {
        if (lo == hi) return lo;
        int inLeft = ct[b] - ct[a - 1];
        if (k <= inLeft) return left -> kth(ct[a - 1] + 1, ct[b], k);
        return right -> kth(a - ct[a - 1], b - ct[b], k - inLeft);
    }

    int range(int x, int y, int a, int b) {
        return range(x, y, b) - range(x, y, a - 1);
    }
    
private:
    int range(int x, int y, int b) {
        if (hi < x or y < lo) return 0;
        if (x <= lo and hi <= y) return b;
        int sum = 0;
        if (left) sum = left -> range(x, y, ct[b]);
        if (right) sum += right -> range(x, y, b - ct[b]);
        return sum;
    }

    int ocurrences(int b, int k) {
        if (k < lo or k > hi) return 0;
        if (lo == hi) return b;
        if (k <= mid) return left -> ocurrences(ct[b], k);
        return right -> ocurrences(b - ct[b], k);
    }
};

int N, Q, sigma;
vector <int> arr, tmp;
unordered_map <int, int> mp, inv_mp;
WaveletTree *tree;

void readArray() {
    scanf("%d %d", &N, &Q);
    arr.resize(N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
}

void compress() {
    tmp = arr;
    sort(all(tmp));
    mp[tmp[0]] = ++sigma;
    inv_mp[sigma] = tmp[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] != arr[i - 1]) {
            mp[tmp[i]] = ++sigma;
            inv_mp[sigma] = tmp[i];
        }
    }
    for (int i = 0; i < N; i++) {
        arr[i] = mp[arr[i]];
    }
}

int main() {
    readArray();
    compress();
    tree = new WaveletTree(all(arr), 1, sigma);
    while (Q--) {
        int L, R, K;
        scanf("%d %d %d", &L, &R, &K);
        printf("%d\n", inv_mp[tree -> kth(L, R, K)]);
    }
    delete tree;
    return (0);
}
