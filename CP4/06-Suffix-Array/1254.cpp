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

struct DSU {
  vi root;
  vi ss;
  int n_sets;

  DSU (int n): n_sets(n) {
    root.resize(n);
    iota(all(root), 0);
    ss = vi(n, 1);
  }

  int get (int u) {
    return root[u] = (u == root[u]) ? u : get(root[u]);
  }

  int join (int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return 0;
    if (ss[u] < ss[v]) swap(u, v);
    root[v] = u;
    ss[u] += ss[v];
    n_sets -= 1;
    return 1;
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  string s = "";
  vi pos;
  vi len;
  vector <pair <string, int>> ss;
  for (int i = 0; i < n; i++) {
    string si;
    cin >> si;
    s += si + "#";
    pos.pb(sz(s));
    len.pb(sz(si));
    ss.emplace_back(si, i);
  }
  sort(all(ss));
  DSU dsu(n);
  for (int i = 1; i < n; i++) {
    if (ss[i].first == ss[i - 1].first) {
      dsu.join(ss[i].second, ss[i - 1].second);
    }
  }
  vi color(sz(s), -1);
  int c = 0;
  int l = 0;
  for (int pi: pos) {
    int r = pi - 1;
    for (int i = l; i < r; i++) color[i] = c;
    c += 1;
    l = pi;
  }
  SuffixArray sa(s);
  vi where(sz(s) + 1);
  for (int i = 0; i < sz(sa.sa); i++) where[sa.sa[i]] = i;
  vi last(n, -1);
  vi nxt(sz(sa.sa), -1);
  for (int i = n; i < sz(sa.sa); i++) {
    int x = color[sa.sa[i]];
    if (last[x] != -1) {
      nxt[last[x]] = i;
    }
    last[x] = i;
  }
  vector <vi> ans(sz(sa.sa));
  auto cmp = [&] (int cx, int cy) {
    if (len[cx] != len[cy]) return len[cx] < len[cy];
    if (dsu.get(cx) != dsu.get(cy)) {
      int s1 = (cx == 0) ? 0 : pos[cx - 1];
      int s2 = (cy == 0) ? 0 : pos[cy - 1];
      return where[s1] < where[s2];
    }
    return cx < cy;
  };
  int z = sz(sa.sa);
  vector <vi> st(4 * z);
  auto merge = [&] (const vi& z1, const vi& z2) {
    vi z = z1;
    z.insert(end(z), all(z2));
    sort(all(z));
    z.erase(unique(all(z)), end(z));
    sort(all(z), cmp);
    while (sz(z) > 10) z.pop_back();
    return z;
  };
  function <void(int,int,int)> build = [&] (int u, int l, int r) -> void {
    if (l == r) {
      st[u] = {color[sa.sa[l]]};
      return;
    }
    int m = (l + r) >> 1;
    int lu = u << 1;
    int ru = lu | 1;
    build(lu, l, m);
    build(ru, m + 1, r);
    st[u] = merge(st[lu], st[ru]);
  };
  build(1, n, z - 1);
  const vi NIL = {};
  function <vi(int,int,int,int,int)> query = [&] (int u, int l, int r, int L, int R) -> vi {
    if (R < l or r < L) return NIL;
    if (L <= l and r <= R) return st[u];
    int m = (l + r) >> 1;
    return merge(query(2 * u, l, m, L, R), query(2 * u + 1, m + 1, r, L, R));
  };
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    auto [from, to] = sa.find(s);
    if (from == -1) {
      cout << -1 << '\n';
      continue;
    }
    vi pos = query(1, n, z - 1, from, to);
    for (int i = 0; i < sz(pos); i++) cout << 1 + pos[i] << " \n"[i == sz(pos) - 1];
  }
  return (0);
}
