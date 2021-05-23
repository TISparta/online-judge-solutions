// Tags: Game Theory
// Difficulty: 6.7
// Priority: 1
// Date: 23-05-2021

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
  string s;
  cin >> s;
  int n = sz(s);
  vi grundy(n + 1, 0);
  grundy[0] = 0;
  grundy[1] = 1;
  vi val(n + 2, 0);
  for (int len = 2; len <= n; len++) {
    fill(all(val), 0);
    val[grundy[0] ^ grundy[len - 2]] = 1; // delete a border
    for (int i = 1; i + 1 < len; i++) {
      val[grundy[i - 1] ^ grundy[len - i - 2]] = 1;
    }
    int mex = 0;
    while (val[mex]) mex += 1;
    grundy[len] = mex;
  }
  auto spv = [&] (int l, int r) {
    int xsum = 0;
    for (int i = l + 1; i + 1 <= r; i++) {
      if (s[i - 1] != s[i + 1]) continue;
      int j = i;
      while (j + 2 <= r and s[j] == s[j + 2]) j += 1;
      xsum ^= grundy[j - i + 1];
      i = j;
    }
    return xsum;
  };
  if (spv(0, n - 1) == 0) {
    cout << "Second\n";
  } else {
    cout << "First\n";
    for (int i = 1; i + 1 < n; i++) {
      if (s[i - 1] == s[i + 1] and (spv(0, i - 1) ^ spv(i + 1, n - 1)) == 0) {
        cout << i + 1 << '\n';
        break;
      }
    }
  }
  return (0);
}
