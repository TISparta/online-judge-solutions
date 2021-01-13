// Implementation
// 2
// 13-01-2021

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
  auto die = [&] () {
    cout << "No solution\n";
    exit(0);
  };
  vector <string> ans;
  string cur = "";
  int prev = 0;
  for (char ch: s) {
    cur += ch;
    if (prev) {
      ans.pb(cur);
      cur = "";
    }
    prev = (ch == '@');
  }
  if (prev or ans.empty()) die();
  ans.back() += cur;
  for (auto si: ans) {
    if (si.empty() or si.front() == '@' or si.back() == '@') die();
  }
  for (int i = 0; i < sz(ans); i++) {
    cout << ans[i] << ",\n"[i == sz(ans) - 1];
  }
  return (0);
}
