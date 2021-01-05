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
  int n;
  bool blank = false;
  while (cin >> n, n != 0) {
    if (blank) cout << '\n';
    blank = true;
    vi pos;
    string s = "";
    if (n == 1) {
      cin >> s;
      cout << s << '\n';
      continue;
    }
    vi mx_len;
    for (int i = 0; i < n; i++) {
      string si;
      cin >> si;
      for (int j = sz(si); j >= 0; j--) mx_len.pb(j);
      pos.pb(sz(s));
      s += si + "#";
    }
    mx_len.pb(0);
    vi color(sz(s) + 1, 0);
    int c = 1;
    for (int i = sz(pos) - 1; i > 0; i--) {
      int from = pos[i] - 1;
      int to = pos[i - 1];
      for (int j = from; j >= to; j--) color[j] = c;
      c += 1;
    }
    SuffixArray sa(s);
    vi nxt(sz(sa.sa));
    nxt[sz(sa.sa) - 1] = sz(sa.sa);
    for (int i = sz(sa.sa) - 2; i >= 0; i--) {
      int x = sa.sa[i];
      int y = sa.sa[i + 1];
      if (color[x] == color[y]) nxt[i] = nxt[i + 1];
      else nxt[i] = i + 1;
    }
    int need = n / 2 + 1;
    int best = 0;
    vi take;
    STable st(0, sz(sa.lcp) - 1, sa.lcp);
    for (int i = 1; i < sz(sa.sa); i++) {
      if (s[sa.sa[i]] == '#') continue;
      set <int> got;
      got.insert(color[sa.sa[i]]);
      int cur = i;
      while (cur < sz(sa.sa) and nxt[cur] < sz(sa.sa) and sz(got) < need) {
        cur = nxt[cur];
        got.insert(color[sa.sa[cur]]);
      }
      if (sz(got) == need) {
        int len = st.query(i, cur - 1);
        len = min(len, mx_len[sa.sa[i]]);
        if (len > 0) {
          if (len > best) {
            best = len;
            take.clear();
            take.pb(sa.sa[i]);
          } else if (len == best) {
            take.pb(sa.sa[i]);
          }
        }
      }
    }
    if (best == 0) {
      cout << "?\n";
    } else {
      string prev = "";
      for (int from: take) {
        string si = s.substr(from, best);
        if (si == prev) continue;
        cout << si << '\n';
        prev = si;
      }
    }
  }
  return (0);
}
