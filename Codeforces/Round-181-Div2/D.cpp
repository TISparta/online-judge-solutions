// DP on trees
// 5
// 08-08-2020

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

const int mod = 7340033;

int add (ll x, ll y) { return (x + y) % mod; }
int mul (ll x, ll y) { return (x * y) % mod; }

const int MAX_K = 1e3 + 10;
const int MAX_H = 35;

int dp[MAX_H][MAX_K];

void rec (int h) {
  dp[h][0] = 1;
  if (h == 0) return;
  rec(h - 1);
  vi rdp(MAX_K, 0);
  rdp[0] = 1;
  for (int i = 1; i <= 4; i++) {
    vi ndp(MAX_K, 0);
    for (int k = 0; k < MAX_K; k++) {
      for (int t = 0; t <= k; t++) {
        ndp[k] = add(ndp[k], mul(rdp[t], dp[h - 1][k - t]));
      }
    }
    rdp = ndp;
  }
  for (int i = 0; i < MAX_K - 1; i++) {
    dp[h][i + 1] = rdp[i];
  }
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  rec(MAX_H - 1);
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    int h = 0;
    while (n > 1 and n % 2 == 1) {
      n /= 2;
      h++;
    }
    cout << dp[h][k] << '\n';
  }
  return (0);
}
