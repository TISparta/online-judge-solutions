// Constructive, Brute Force
// 5
// 19-11-2020

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
  vector <vi> ans(n, vi(n));
  for (int i = 0; i < n; i++) {
    cout << "? " << i << ' ' << 0 << endl;
    cin >> ans[i][0];
  }
  for (int i = 0; i < n; i++) {
    cout << "? " << 0 << ' ' << i << endl;
    cin >> ans[0][i];
  }
  vi pp;
  int cnt = 0;
  for (int b0 = 0; b0 < n; b0++) {
    vi p(n);
    vi b(n, -1);
    for (int i = 0; i < n; i++) {
      p[i] = ans[i][0] ^ b0;
      if (not (0 <= p[i] and p[i] < n)) break;
      b[p[i]] = i;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (b[i] == -1) ok = false;
    }
    if (not ok) continue;
    for (int i = 0; i < n; i++) {
      ok &= (ans[i][0] == (p[i] ^ b[0]));
      ok &= (ans[0][i] == (p[0] ^ b[i]));
    }
    if (not ok) continue;
    if (pp.empty()) pp = p;
    cnt += 1;
  }
  cout << "!" << endl;
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << pp[i];
    if (i != n - 1) cout << ' ';
  }
  cout << endl;
  return (0);
}
