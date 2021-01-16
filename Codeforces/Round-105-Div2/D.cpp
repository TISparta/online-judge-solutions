// DP, Probabilities
// 4
// 08-04-2020

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <ll> vll;

const int N = 1001;

double dp[N][N][2];
bool vis[N][N][2];

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int w, b;
  cin >> w >> b;
  memset(vis, false, sizeof vis);
  function <double(int,int,int)> rec = [&] (int w, int b, int turn) -> double {
    if (w <= 0 or b < 0) return 0.0;
    if (vis[w][b][turn]) return dp[w][b][turn];
    vis[w][b][turn] = true;
    double& ret = dp[w][b][turn];
    if (turn == 0) { // princess
      ret = 1.0 * w / (w + b);
      ret += 1.0 * b / (w + b) * rec(w, b - 1, 1);
    } else { // dragon
      if (b == 0) {
        ret = 0;
      } else {
        ret = 1.0 * b / (w + b) * (
          1.0 * w / (w + b - 1) * rec(w - 1, b - 1, 0) +
          1.0 * (b - 1) / (w + b - 1) * rec(w, b - 2, 0)
        );
      }
    }
    return ret;
  };
  cout << fixed << setprecision(12) << rec(w, b, 0) << '\n';
  return (0);
}
