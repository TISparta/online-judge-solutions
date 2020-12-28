// Trie
// 4
// 26-12-2020

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
  struct Trie {
    int child[2] = {-1, -1};
    int cnt = 0;
  };
  vector <Trie> trie;
  trie.pb(Trie{});
  const int LG = 30;
  auto update = [&] (int num, int flag) {
    int node = 0;
    for (int bit = LG; bit >= 0; bit--) {
      int b = (num >> bit) & 1;
      if (trie[node].child[b] == -1) {
        trie[node].child[b] = sz(trie);
        trie.pb(Trie{});
      }
      node = trie[node].child[b];
      trie[node].cnt += flag;
    }
  };
  auto lt = [&] (int p, int x) {
    int ret = 0;
    int node = 0;
    for (int bit = LG; bit >= 0 and node != -1; bit--) {
      int bp = (p >> bit) & 1;
      int bx = (x >> bit) & 1;
      int nxt = -1;
      for (int b: {0, 1}) {
        if (trie[node].child[b] == -1) continue;
        if ((b ^ bp) < bx) {
          ret += trie[trie[node].child[b]].cnt;
        }
        if ((b ^ bp) == bx) {
          nxt = trie[node].child[b];
        }
      }
      node = nxt;
    }
    return ret;
  };
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int p;
      cin >> p;
      update(p, 1);
    }
    if (type == 2) {
      int p;
      cin >> p;
      update(p, -1);
    }
    if (type == 3) {
      int p, x;
      cin >> p >> x;
      cout << lt(p, x) << '\n';
    }
  }
  return (0);
}
