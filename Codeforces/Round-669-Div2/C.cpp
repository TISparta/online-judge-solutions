// Constructive, Math
// 4
// 08-09-2020

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
  int x = 1;
  auto ask = [&] (int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int k;
    cin >> k;
    if (k == -1) return (0);
    return k;
  };
  vi ans(n + 1, -1);
  set <int> pos;
  set <int> used;
  for (int i = 1; i <= n; i++) {
    pos.insert(i);
    used.insert(i);
  }
  while (sz(pos) >= 2) {
    int x = *begin(pos);
    pos.erase(begin(pos));
    int y = *begin(pos);
    pos.erase(begin(pos));
    int r1 = ask(x, y);
    int r2 = ask(y, x);
    if (r1 < r2) {
      ans[y] = r2;
      used.erase(r2);
      pos.insert(x);
    } else {
      ans[x] = r1;
      used.erase(r1);
      pos.insert(y);
    }
  }
  cout << "!";
  for (int i = 1; i <= n; i++) {
    if (ans[i] == -1) ans[i] = *begin(used);
    cout << " " << ans[i];
  }
  cout << endl;
  return (0);
}
