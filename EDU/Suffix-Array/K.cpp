// Suffix Array, Sparse Table
// 6
// 03-01-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

struct SuffixArray {
  int n;
  string s;
  vi sa;
  vi lcp;
  const int sigma = 300;

  void counting_sort (int k, const vi& rank) {
    vi cnt(max(sigma, n), 0);
    for (int i = 0; i < n; i++) {
      cnt[(i + k < n) ? rank[i + k] : 0] += 1;
    }
    int sum = 0;
    for (int i = 0; i < sz(cnt); i++) {
      int ci = cnt[i];
      cnt[i] = sum;
      sum += ci;
    }
    vi tmp_sa(n);
    for (int i = 0; i < n; i++) {
      int pos = (sa[i] + k < n) ? rank[sa[i] + k] : 0;
      tmp_sa[cnt[pos]++] = sa[i];
    }
    sa.swap(tmp_sa);
  }

  void construct_SA () {
    sa.resize(n);
    iota(all(sa), 0);
    vi rank(n, 0);
    for (int i = 0; i < n; i++) rank[i] = s[i];
    for (int k = 1; k < n; k <<= 1) {
      counting_sort(k, rank);
      counting_sort(0, rank);
      int r = 0;
      vi tmp_rank(n);
      tmp_rank[sa[0]] = r;
      for (int i = 1; i < n; i++) {
        if (rank[sa[i]] == rank[sa[i - 1]] and
            rank[sa[i] + k] == rank[sa[i - 1] + k]) {
          tmp_rank[sa[i]] = r;
        } else {
          tmp_rank[sa[i]] = ++r;
        }
      }
      rank.swap(tmp_rank);
      if (rank[sa[n - 1]] == n - 1) break;
    }
  }

  pii find (const string& p) {
    pii ret;
    {
      int l = 0, h = n - 1;
      while (l != h) {
        int m = (l + h) >> 1;
        if (s.compare(sa[m], sz(p), p) >= 0) h = m;
        else l = m + 1;
      }
      if (s.compare(sa[l], sz(p), p) != 0) return pii(-1, -2);
      ret.first = l;
    }
    {
      int k = 0;
      while ((1 << k) < n) k += 1;
      int h = ret.first;
      for (int bit = k - 1; bit >= 0; bit--) {
        if (h + (1 << bit) < n and s.compare(sa[h + (1 << bit)], sz(p), p) == 0) {
          h += (1 << bit);
        }
      }
      ret.second = h;
    }
    return ret;
  }

  // lcp(i) = LCP(sa(i), sa(i + 1))
  void construct_LCP () {
    vi rank(n, 0);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    int k = 0;
    lcp.resize(n - 1, 0);
    for (int i = 0; i < n; i++) {
      if (rank[i] == n - 1) { k = 0; continue; }
      int j = sa[rank[i] + 1];
      while (max(i, j) + k < n and s[i + k] == s[j + k]) k += 1;
      lcp[rank[i]] = k;
      k = max(0, k - 1);
    }
  }

  SuffixArray (const string& ss) {
    s = ss;
    s += "$";
    n = sz(s);
    construct_SA();
    construct_LCP();
  }
};

struct STable {
  const int LG = 20;
  vector <vi> st;
  
  inline int op (int x, int y) {
    return min(x, y);
  }

  STable (int l, int r, const vi& arr) {
    st = vector <vi> (r + 1, vi(LG));
    for (int i = l; i <= r; i++) {
      st[i][0] = arr[i];
    }
    for (int bit = 1; bit < LG; bit++) {
      for (int i = l; i + (1 << bit) - 1 <= r; i++) {
        int j = i + (1 << (bit - 1));
        st[i][bit] = op(st[i][bit - 1], st[j][bit - 1]);
      }
    }
  }

  int query (int l, int r) {
    if (l == r) return st[l][0];
    int x = 31 - __builtin_clz(r - l);
    int l2 = r - (1 << x) + 1;
    return op(st[l][x], st[l2][x]);
  }

};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  string s;
  cin >> s;
  int n = sz(s);
  SuffixArray sa1(s);
  STable st1(0, sz(sa1.lcp) - 1, sa1.lcp);
  vi where1(n + 1);
  for (int i = 0; i < n + 1; i++) where1[sa1.sa[i]] = i;
  reverse(all(s));
  SuffixArray sa2(s);
  STable st2(0, sz(sa2.lcp) - 1, sa2.lcp);
  vi where2(n + 1);
  for (int i = 0; i < n + 1; i++) where2[sa2.sa[i]] = i;
  int ans = 1;
  for (int len = 1; len < n; len++) {
    int i = 0;
    while (i + len - 1 < n) {
      int j = i + len;
      int k = 1;
      while (j + len - 1 < n and st1.query(min(where1[i], where1[j]), max(where1[i], where1[j]) - 1) >= len) {
        j += len;
        k += 1;
      }
      int extra = 0;
      if (j < n) extra += st1.query(min(where1[i], where1[j]), max(where1[i], where1[j]) - 1);
      if (0 < i) extra += st2.query(min(where2[n - i], where2[n - i - len]), max(where2[n - i], where2[n - i - len]) - 1);
      if (extra >= len) k += 1;
      ans = max(ans, k);
      i = j;
    }
  }
  cout << ans << '\n';
  /*
  vi where(n + 1);
  for (int i = 0; i < n + 1; i++) where[sa.sa[i]] = i;
  int ans = 1;
  for (int len = 1; len < n; len++) {
    vi dp(n, 0);
    dp[n - len] = 1;
    for (int i = n - len - 1; i >= 0; i--) {
      dp[i] = 1;
      int x = where[i];
      int y = where[i + len];
      if (x > y) swap(x, y);
      int mn = sa.lcp[x];
      for (int j = x; j < y; j++) mn = min(mn, sa.lcp[j]);
      if (mn >= len) dp[i] = 1 + dp[i + len];
    }
    ans = max(ans, *max_element(all(dp)));
  }
  */
  return (0);
}
