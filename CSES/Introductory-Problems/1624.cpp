// Backtracking
// 2
// 04-09-2020

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
  const int N = 8;
  vector <string> s(N);
  for (int i = 0; i < N; i++) cin >> s[i];
  vpii pos;
  auto valid = [&] (int row, int col) {
    if (s[row][col] != '.') return false;
    for (auto pp: pos) {
      if (pp.second == col) return false;
      if (row - pp.first == col - pp.second) return false;
      if (row - pp.first == -col + pp.second) return false;
    }
    return true;
  };
  function <int(int)> backtrack = [&] (int row) -> int {
    if (row == N) return 1;
    int ret = 0;
    for (int col = 0; col < N; col++) {
      if (valid(row, col)) {
        pos.emplace_back(row, col);
        ret += backtrack(row + 1);
        pos.pop_back();
      }
    }
    return ret;
  };
  cout << backtrack(0) << '\n';
  return (0);
}
