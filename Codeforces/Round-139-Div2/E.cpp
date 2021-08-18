// Tags: Pattern Finding
// Difficulty: 6.3
// Priority: 2
// Date: 11-11-2020

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

void simulation () {
  for (int p = 1; p <= 30; p++) {
    bool valid = true;
    int z = (1 << p) - 1;
    for (int x = 1; x * 2 < z; x++) {
      int v = z - (x / 2);
      if (v % (1 + x) == 0) {
        valid = false;
        break;
      }
    }
    if (valid) cout << p << endl;
  }
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  //simulation();
  vi p = {1, 2, 4, 6, 12, 16, 18, 30, 60, 88, 106, 126, 520, 606, 1278, 2202, 2280, 3216, 4252, 4422, 9688, 9940, 11212, 19936, 21700, 23208, 44496, 86242, 110502, 132048, 216090, 756838, 859432, 1257786, 1398268, 2976220, 3021376, 6972592, 13466916, 20996010};
  const int mod = 1e9 + 7;
  ll ret = 1;
  int n;
  cin >> n;
  ll a = 2, b = p[n - 1];
  while (b) {
    if (b & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  ret -= 1;
  if (ret < 0) ret += mod;
  cout << ret << '\n';
  return (0);
}
