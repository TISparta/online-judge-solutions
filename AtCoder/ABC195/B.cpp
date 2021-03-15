// Brute Force
// 2
// 13-03-2021

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
  int a, b, w;
  cin >> a >> b >> w;
  w *= 1000;
  const int N = 1000001;
  vi can(N, 0);
  for (int i = 1; i < N; i++) {
    int l = a * i;
    int r = b * i;
    if (l <= w and w <= r) can[i] = 1;
  }
  int mn = INT_MAX;
  int mx = INT_MIN;
  for (int i = 1; i < N; i++) {
    if (can[i]) {
      mn = min(mn, i);
      mx = max(mx, i);
    }
  }
  if (mn == INT_MAX) {
    cout << "UNSATISFIABLE\n";
  } else {
    cout << mn << ' ' << mx << '\n';
  }
  return (0);
}
