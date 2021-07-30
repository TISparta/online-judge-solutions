// Tags: Sorting
// Difficulty: 2.5
// Priority: 1
// Date: 23-07-2021

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector <string> s(n);
    vector <vi> cnt(n, vi(5, 0));
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (char ch: s[i]) {
        cnt[i][ch - 'a'] += 1;
      }
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
      vi z(n);
      iota(all(z), 0);
      sort(all(z), [&] (int x, int y) {
        int s1 = 2 * cnt[x][i] - sz(s[x]);
        int s2 = 2 * cnt[y][i] - sz(s[y]);
        return s1 > s2;
      });
      int a = 0;
      int b = 0;
      int cur_ans = 0;
      for (int x: z) {
        a += cnt[x][i];
        b += (sz(s[x]) - cnt[x][i]);
        if (a <= b) break;
        cur_ans += 1;
      }
      ans = max(ans, cur_ans);
    }
    cout << ans << '\n';
  }
  return (0);
}
