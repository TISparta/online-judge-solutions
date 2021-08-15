// Tags: Trie, Greedy
// Difficulty: 5.5
// Priority: 3
// Date: 14-04-2021

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

struct Trie {
  vector <vi> trie;
  vi f;
  Trie () {
    trie.pb(vi(2, -1));
    f.pb(0);
  }
  void add (const string& s) {
    int cur = 0;
    for (char ch: s) {
      int d = ch - '0';
      if (trie[cur][d] == -1) {
        trie[cur][d] = sz(trie);
        trie.pb(vi(2, -1));
        f.pb(0);
      }
      cur = trie[cur][d];
    }
    f[cur] = 1;
  }
  bool in (const string& s) {
    int cur = 0;
    for (char ch: s) {
      int d = ch - '0';
      if (trie[cur][d] == -1) return false;
      cur = trie[cur][d];
    }
    return f[cur];
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector <string> s(n);
    auto get = [&] (const string& s) {
      return 2 * (s.front() - '0') + (s.back() - '0');
    };
    vi cnt(4, 0);
    Trie trie;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      trie.add(s[i]);
      cnt[get(s[i])] += 1;
    }
    if (cnt[1] == 0 and cnt[2] == 0 and cnt[0] != 0 and cnt[3] != 0) {
      cout << -1 << '\n';
      continue;
    }
    vi ans;
    int id = (cnt[1] > cnt[2]) ? 1 : 2;
    for (int i = 0; i < n and abs(cnt[1] - cnt[2]) > 1; i++) {
      int z = get(s[i]);
      if (z != id) continue;
      reverse(all(s[i]));
      if (trie.in(s[i])) continue;
      ans.pb(i);
      if (id == 1) {
        cnt[1] -= 1;
        cnt[2] += 1;
      }
      if (id == 2) {
        cnt[2] -= 1;
        cnt[1] += 1;
      }
    }
    cout << sz(ans) << '\n';
    bool first = true;
    for (int ans_i: ans) {
      if (not first) cout << ' ';
      cout << 1 + ans_i;
      first = false;
    }
    cout << '\n';
  }
  return (0);
}
