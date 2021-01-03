// Suffix Array, Segment Tree
// 5
// 02-01-2021

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

struct STree {
  int from, to;
  const int INF = 1e9;
  struct State {
    int cnt = 0;
    ll sum = 0;
    bool lazy = false;
  };
  vector <State> st;
  State NIL{0, 0, false};

  void build (int u, int l, int r, const vi& arr) {
    if (l == r) {
      st[u].sum = arr[l];
      return;
    }
    int m = (l + r) >> 1;
    int lu = u << 1;
    int ru = lu | 1;
    build(lu, l, m, arr);
    build(ru, m + 1, r, arr);
    st[u] = merge(st[lu], st[ru]);
  }

  STree (int l, int r, const vi& arr): from(l), to(r) {
    st.resize(4 * r);
    build(1, l, r, arr);
  }

  State merge (State lu, State ru) {
    return State{lu.cnt + ru.cnt, lu.sum + ru.sum, false};
  }

  void push (int u, int l, int r) {
    if (st[u].lazy == false) return;
    st[u].cnt = 0;
    st[u].sum = 0;
    if (l != r) {
      st[2 * u].lazy = true;
      st[2 * u + 1].lazy = true;
    }
    st[u].lazy = false;
  }

  void update (int L, int R, int val, int u, int l, int r) {
    push(u, l, r);
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      if (l == r) {
        st[u] = State{val, 1LL * val * l, false};
      } else {
        st[u].lazy = true;
        push(u, l, r);
      }
      return;
    }
    int m = (l + r) >> 1;
    int lu = u << 1;
    int ru = lu | 1;
    update(L, R, val, lu, l, m);
    update(L, R, val, ru, m + 1, r);
    st[u] = merge(st[lu], st[ru]);
  }

  void update (int L, int R, int val) { update(L, R, val, 1, from, to); }

  State query (int L, int R, int u, int l, int r) {
    push(u, l, r);
    if (r < L or R < l) return NIL;
    if (L <= l and r <= R) return st[u];
    int m = (l + r) >> 1;
    return merge(query(L, R, (u << 1), l, m), query(L, R, (u << 1) | 1, m + 1, r));
  }

  State query (int L, int R) { return query(L, R, 1, from, to); }

};


int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  string s;
  cin >> s;
  SuffixArray sa(s);
  ll ans = 1LL * sz(s) * (sz(s) + 1) / 2;
  int m = sz(s) + 1;
  vi frec(m, 0);
  STree tree(0, m - 1, frec);
  for (int i = sz(sa.lcp) - 1; i >= 0; i--) {
    int cnt1 = tree.query(sa.lcp[i] + 1, m - 1).cnt;
    int cnt2 = tree.query(sa.lcp[i], sa.lcp[i]).cnt;
    tree.update(sa.lcp[i], m - 1, 0);
    tree.update(sa.lcp[i], sa.lcp[i], 1 + cnt1 + cnt2);
    ans += tree.query(0, m - 1).sum;
  }
  /*
  for (int i = 0; i < sz(sa.lcp); i++) {
    int mn = sa.lcp[i];
    mn = sa.lcp[i];
    for (int j = i; j < sz(sa.lcp); j++) {
      mn = min(mn, sa.lcp[j]);
      ans += mn;
    }
  }
  */
  cout << ans << '\n';
  return (0);
}
