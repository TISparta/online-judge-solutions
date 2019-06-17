/**
 * > Author : TISparta
 * > Date : 17-06-19
 * > Tags : Graphs
 * > Difficulty : 7 / 10
 * > Points: 46
 */

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

ll sq (ll X) { return X * X; }

struct Edge {
  int from, to, i;
  ll benefit;
  Edge () {}
  Edge (int from, int to, int i, ll benefit):
    from(from), to(to), i(i), benefit(benefit) {
    if (from > to) swap(from, to);  
  }
  bool operator == (const Edge& other) const {
    return i == other.i;
  }
  bool operator < (const Edge& other) const {
    return benefit > other.benefit;
  }
};

int main () {
  int n, m;
  cin >> n >> m;
  vector <int> s(n + 1);
  vector <int> w(m + 1);
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= m; i++) cin >> w[i];
  vector <vector <pii>> G(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v, i);
    G[v].emplace_back(u, i);
  }
  const int BLACK = 0;
  const int WHITE = 1;
  const int GRAY  = -1;
  vector <int> color(n + 1, GRAY);
  vector <int> component(n + 1, -1);
  vector <int> flip(n + 1, false);
  vector <Edge> to_delete;
  ll black = 0;
  ll white = 0;
  auto computeBenefit = [&] (int from, int to, int i) -> ll {
    return sq(s[from] / 2) + sq(s[to] / 2);
  };
  auto bfs = [&] () -> void {
    int cc = -1;
    for (int u = 1; u <= n; u++) {
      if (color[u] != GRAY) continue;
      ll sum_black = 0, sum_white = 0;
      cc++;
      queue <int> Q;
      Q.push(u);
      component[u] = cc;
      color[u] = BLACK;
      while (not Q.empty()) {
        int from = Q.front();
        Q.pop();
        for (auto pp: G[from]) {
          int to = pp.first;
          int i = pp.second;
          component[to] = cc;
          if (color[to] == GRAY) {
            color[to] = 1 ^ color[from];
            Q.push(to);
          } else if (color[to] == color[from]) {
            if (w[i] > 32 * s[from] * s[to]) continue;
            to_delete.push_back(Edge(from, to, i, computeBenefit(from, to, i)));
            if (color[to] == WHITE) sum_white += w[i];
            if (color[to] == BLACK) sum_black += w[i];
          }
        }
      }
      ll f1 = sq((white + sum_white) / 2) + sq((black + sum_black) / 2);
      ll f2 = sq((white + sum_black) / 2) + sq((black + sum_white) / 2);
      if (f1 <= f2) {
        white += sum_white;
        black += sum_black;
      } else {
        white += sum_black;
        black += sum_white;
        flip[cc] = true;
      }
    }
  };
  bfs();
  ll X = 0LL;
  ll cur = sq(white / 2) + sq(black / 2);
  vector <bool> used(m + 1, false);
  sort(all(to_delete));
  while (not to_delete.empty()) {
    auto e = to_delete.back();
    to_delete.pop_back();
    if (used[e.i]) continue;
    ll add = w[e.i];
    ll w_sum, b_sum;
    if (color[e.from] == BLACK) {
      if (flip[component[e.from]]) w_sum = s[e.from], b_sum = s[e.to];
      else b_sum = s[e.from], w_sum = s[e.to];
    } else {
      if (flip[component[e.from]]) b_sum = s[e.from], w_sum = s[e.to];
      else w_sum = s[e.from], b_sum = s[e.to];
    }
    ll n_white = white - w_sum;
    ll n_black = black - b_sum;
    ll n_cost = X + add + sq(n_white / 2) + sq(n_black / 2);
    if (n_cost > cur) {
      continue;
    }
    cout << e.i << endl;
    used[e.i] = true;
    int type;
    cin >> type;
    if (type == 0) {
      int i, x;
      cin >> i >> x;
      s[i] = x;
    }
    else if (type == 1) {
      int i, y;
      cin >> i >> y;
      w[i] = y;
    }
    cur = n_cost;
    white = n_white;
    black = n_black;
  }
  cout << -1 << endl;
  string ans = "";
  for (int i = 1; i <= n; i++) {
    if (flip[component[i]]) {
      if (color[i] == BLACK) ans += 'G';
      else ans += 'C';
    } else {
      if (color[i] == BLACK) ans += 'C';
      else ans += 'G';
    }
  }
  cout << ans << endl;
  return (0);
}
