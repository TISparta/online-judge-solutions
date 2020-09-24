// Implementation
// 3
// 05-08-2020

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
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set <int> ones;
    set <int> zeros;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') zeros.insert(i);
      if (s[i] == '1') ones.insert(i);
    }
    vi ans(n, 0);
    int ans_k = 0;
    for (int i = 0; i < n; i++) {
      if (ans[i] != 0) continue;
      ans_k++;
      int cur = i;
      while (cur < n) {
        ans[cur] = ans_k;
        if (s[cur] == '0') {
          zeros.erase(cur);
          auto it = ones.upper_bound(cur);
          if (it == end(ones)) break;
          cur = *it;
        } else {
          ones.erase(cur);
          auto it = zeros.upper_bound(cur);
          if (it == end(zeros)) break;
          cur = *it;
        }
      }
    }
    cout << ans_k << '\n';
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
  return (0);
}
