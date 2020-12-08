// DSU
// 3
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

struct DSU {
  vi root;
  int n_sets;

  DSU (int n) {
    root.resize(n);
    iota(all(root), 0);
    n_sets = n;
  }

  int get (int u) {
    return root[u] = (u == root[u]) ? u : get(root[u]);
  }

  int join (int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return 0;
    n_sets -= 1;
    if (u < v) swap(u, v);
    root[u] = v;
    return 1;
  }
};


int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    dsu.join(x - 1, y - 1);
  }
  cout << dsu.n_sets << '\n';
  return (0);
}
