// BFS
// 2
// 08-12-2020

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

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector <vpii> g(n + 1);
  int s = -1;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
    if (w & 1) s = i;
  }
  if (s == -1) {
    for (int i = 1; i <= n; i++) cout << 0 << '\n';
    return (0);
  }
  queue <int> q;
  q.push(s);
  vi color(n + 1, -1);
  color[s] = 0;
  while (not q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [v, w]: g[u]) {
      if (color[v] == -1) {
        color[v] = (w & 1) ? 1 - color[u] : color[u];
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << color[i] << '\n';
  return (0);
}
