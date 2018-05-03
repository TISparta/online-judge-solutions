/**
 * > Author : TISparta
 * > Date : 03-04-18
 * > Tags : Wavelet Tree, BIT
 * > Difficulty : 7 / 10
 */

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()

using namespace std;

typedef vector <int>::iterator iter;

struct BIT {
    int sz;
    vector <int> ft;
    BIT() {}

    void init(int sz_) {
        sz = sz_ + 1;
        ft.resize(sz, 0);
    }

    void update(int pos, const int& var) {
        while (pos < sz) {
            ft[pos] += var;
            pos += pos bitand -pos;
        }
    }

    int get(int pos) {
        int sum = 0;
        while (pos) {
            sum += ft[pos];
            pos = pos bitand (pos - 1);
        }
        return sum;
    }
};

struct WaveletTree {
    WaveletTree *left = 0, *right = 0;
    int lo, hi, mid;
    iter B, E;
    vector <int> ct;
    BIT active;

    WaveletTree() {}

    WaveletTree(iter b, iter e, int lo_, int hi_) {
        B = b, E = e;
        lo = lo_, hi = hi_;
        mid = (lo + hi) >> 1;
        if (b >= e) return;
        active.init(e - b + 1);
        ct.reserve(e - b + 1);
        ct.emplace_back(0);
        for (auto it = b; it != e; it++) {
            ct.emplace_back(ct.back() + ((*it) <= mid));
            active.update(it - b + 1, 1);
        }
        iter pivot = stable_partition(b, e, [=](const int& i) { return i <= mid; } );
        if (lo == hi) return;
        left = new WaveletTree(b, pivot, lo, mid);
        right = new WaveletTree(pivot, e, mid + 1, hi);
    };

    ~WaveletTree() {
        delete left;
        delete right;
    }

    int ocurrences(int b, int k) {
        if (k < lo or k > hi) return 0;
        if (lo == hi) return active.get(b);
        if (k <= mid) return left -> ocurrences(ct[b], k)    ;
        return right -> ocurrences(b - ct[b], k);
    }
 
    int ocurrences(int a, int b, int k) {
         return ocurrences(b, k) - ocurrences(a - 1, k);
    }

    void toggle(const int& val, int pos, const bool& state) {
        if (state == 0) active.update(pos, 1);
        else active.update(pos, -1);
        if (lo == hi) return;
        if (val <= mid) left -> toggle(val, ct[pos], state);
        else right -> toggle(val, pos - ct[pos], state);
    }

};

int N, Q, sigma;
vector <int> arr, A, tmp, state;
unordered_map <int, int> mp;
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
    }
    tmp = arr;
}

void read() {
    scanf("%d %d", &N, &Q);
    arr.resize(N);
    A.resize(N);
    state.resize(N, true);
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
        int q, i, l, k, r;
        scanf("%d", &q);
        if (q == 0) {
            scanf("%d %d %d", &i, &l, &k);
            printf("%d\n", tree -> ocurrences(i + 1, l + 1, mp[k]));
        }
        else {
            scanf("%d", &r);
            tree -> toggle(tmp[r], r + 1, state[r]);
            state[r] = 1 - state[r];
        }
    }
    delete tree;
    return (0);
}
