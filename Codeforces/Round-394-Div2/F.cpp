// Cummulative Sums
// 6
// 09-01-2020

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
  int n, m, k;
  cin >> n >> m >> k;
  vector <string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vector <vi> rec(k, vi(4));
  string e(k, ' ');
  vector <vector <vi>> cnt1(30, vector <vi> (n + 2, vi(m + 2, 0)));
  for (int i = 0; i < k; i++) {
    char ch;
    cin >> rec[i][0] >> rec[i][1] >> rec[i][2] >> rec[i][3] >> ch;
    e[i] = ch;
    cnt1[ch - 'a'][rec[i][0]][rec[i][1]]++;
    cnt1[ch - 'a'][rec[i][0]][rec[i][3] + 1]--;
    cnt1[ch - 'a'][rec[i][2] + 1][rec[i][1]]--;
    cnt1[ch - 'a'][rec[i][2] + 1][rec[i][3] + 1]++;
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      for (int d = 0; d < 30; d++) {
        cnt1[d][i][j] += cnt1[d][i - 1][j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int d = 0; d < 30; d++) {
        cnt1[d][i][j] += cnt1[d][i][j - 1];
      }
    }
  }
  vector <vll> acc1(n + 2, vll(m + 2, 0));
  vector <vector <vll>> acc2(30, vector <vll> (n + 2, vll(m + 2, 0)));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      acc1[i][j] = acc1[i - 1][j] + acc1[i][j - 1] - acc1[i - 1][j - 1];
      int sum = 0;
      int x = s[i - 1][j - 1] - 'a';
      for (int d = 0; d < 30; d++) {
        sum += cnt1[d][i][j];
        acc1[i][j] += abs(x - d) * cnt1[d][i][j];
      }
      sum -= cnt1[x][i][j];
      cnt1[x][i][j] = k - sum;
      for (int d = 0; d < 30; d++) {
        acc2[d][i][j] = cnt1[d][i][j] + acc2[d][i - 1][j] + acc2[d][i][j - 1] - acc2[d][i - 1][j - 1];
      }
    }
  }
  ll ans = LLONG_MAX;
  for (int i = 0; i < k; i++) {
    int x1 = rec[i][0], x2 = rec[i][2];
    int y1 = rec[i][1], y2 = rec[i][3];
    ll sum = acc1[x2][y2] - acc1[x2][y1 - 1] - acc1[x1 - 1][y2] + acc1[x1 - 1][y1 - 1];
    ll val = acc1[n][m] - sum;
    int x = e[i] - 'a';
    for (int d = 0; d < 30; d++) {
      ll sum = acc2[d][x2][y2] - acc2[d][x2][y1 - 1] - acc2[d][x1 - 1][y2] + acc2[d][x1 - 1][y1 - 1];
      val += abs(x - d) * sum;
    }
    ans = min(ans, val);
  }
  cout << ans << '\n';
  return (0);
}
