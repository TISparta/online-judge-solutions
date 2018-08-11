/**
 * > Author : TISparta
 * > Date : 08-08-18
 * > Tags : Wavelet Tree
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef int* iter;

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
    for (auto it = b; it != e; it++) {
      ct.emplace_back(ct.back() + ((*it) <= mid));
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

};

const int SIGMA = 1e9 + 10, MAX_N = 3e4 + 10;

int n, arr[MAX_N];

void processQueries () {
  WaveletTree* tree = new WaveletTree(arr, arr + n, 1, SIGMA);
  int q, a, b, c, ans = 0;
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d %d", &a, &b, &c);
    int i = max(1, a xor ans);
    int j = min(n, b xor ans);
    int k = max(0, c xor ans);
    ans = i > j ? 0 : tree -> range(k + 1, SIGMA, i, j);
    printf("%d\n", ans);
  }
}

void readArray() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
}

int main () {
  readArray();
  processQueries();
  return (0);
}
