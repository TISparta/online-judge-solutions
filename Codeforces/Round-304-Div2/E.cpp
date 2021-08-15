// Tags: Flows
// Difficulty: 5.0
// Priority: 2
// Date: 15-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

// O(V E^2)
struct FordFulkerson {
  vector <map <int, int>> cap;
  vi prev;

  FordFulkerson (int n) {
    cap.resize(n);
  }

  void add_edge (int u, int v, int w) {
    cap[u][v] += w;
  }

  int bfs (int s, int t) {
    prev = vi(sz(cap), -1);
    queue <pii> q;
    q.push(pii(s, 1e9));
    while (not q.empty()) {
      auto [u, f] = q.front();
      if (u == t) return f;
      q.pop();
      for (auto [v, c]: cap[u]) {
        if (prev[v] == -1 and c > 0) {
          prev[v] = u;
          q.push(pii(v, min(f, c)));
        }
      }
    }
    return 0;
  }

  void update (int s, int t, int f) {
    while (t != s) {
      int p = prev[t];
      cap[p][t] -= f;
      cap[t][p] += f;
      t = p;
    }
  }

  int max_flow (int s, int t) {
    int flow = 0;
    while (true) {
      int nflow = bfs(s, t);
      if (nflow == 0) break;
      flow += nflow;
      update(s, t, nflow);
    }
    return flow;
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vi b(n + 1);
  for (int i = 1; i <= n; i++) cin >> b[i];
  FordFulkerson ffa(2 * n + 2);
  int source = 0;
  int target = 2 * n + 1;
  const int INF = 1e9;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    ffa.add_edge(u, v + n, INF);
    ffa.add_edge(v, u + n, INF);
  }
  for (int u = 1; u <= n; u++) {
    ffa.add_edge(u, u + n, INF);
    ffa.add_edge(source, u, a[u]);
    ffa.add_edge(u + n, target, b[u]);
  }
  int max_flow = ffa.max_flow(source, target);
  if (max_flow != accumulate(all(b), 0) or accumulate(all(a), 0) != accumulate(all(b), 0)) {
    cout << "NO\n";
    return (0);
  }
  cout << "YES\n";
  for (int u = 1; u <= n; u++) {
    for (int v = 1; v <= n; v++) {
      cout << ffa.cap[v + n][u] << " \n"[v == n];
    }
  }
  return (0);
}
