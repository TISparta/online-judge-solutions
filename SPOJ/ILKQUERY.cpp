/**
 * > Author : TISparta
 * > Date : 03-04-18
 * > Tag : Wavelet Tree
 * > Difficulty : 6 / 10
 */

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()

using namespace std;

typedef vector <int>::iterator iter;

struct WaveletTree {
    WaveletTree *left = 0, *right = 0;
    int lo, hi, mid;
    iter B, E;
    vector <int> ct;

    WaveletTree() {}

    WaveletTree(iter b, iter e, int lo_, int hi_) {
        B = b, E = e;
        lo = lo_, hi = hi_;
        mid = (lo + hi) >> 1;
        if (lo == hi or b >= e) return;
        ct.reserve(e - b + 1);
        ct.emplace_back(0);
        for (auto it = b; it != e; it++)
            ct.emplace_back(ct.back() + ((*it) <= mid));
        iter pivot = stable_partition(b, e, [=](const int& i) { return i <= mid; } );
        left = new WaveletTree(b, pivot, lo, mid);
        right = new WaveletTree(pivot, e, mid + 1, hi);
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

};

int N, Q, sigma;
vector <int> arr, A;
map <pair <int, int>, int> ind;
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
        ind[{arr[i], ct[arr[i]]}] = i;
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
    tree = new WaveletTree(all(arr), 1, sigma);
    while (Q--) {
        int k, i, l, d;
        scanf("%d %d %d", &k, &i, &l);
        d = tree -> kth(1, i + 1, k);
        if (ind.find({d, l}) == ind.end()) puts("-1");
        else printf("%d\n", ind[{d, l}]);
    }
    delete tree;
    return (0);
}
