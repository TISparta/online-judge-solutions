// Math
// 1.0
// 19-04-2021

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
  const int N = 1e4 + 10;
  vi sq(N, 0);
  for (int i = 1; i * i < N; i++) sq[i * i] = 1;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int ai;
      cin >> ai;
      ok &= sq[ai];
    }
    if (ok) cout << "NO\n";
    else cout << "YES\n";
  }
  return (0);
}
