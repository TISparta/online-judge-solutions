// Greedy
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
  string s;
  cin >> s;
  map <char, int> cnt;
  for (char ch: s) cnt[ch]++;
  int odd_cnt = 0;
  for (auto pp: cnt) if (pp.second & 1) odd_cnt += 1;
  if (odd_cnt >= 2) {
    cout << "NO SOLUTION\n";
    return (0);
  }
  string sp = "";
  string si = "";
  for (auto pp: cnt) {
    if (pp.second & 1) si = string(pp.second, pp.first);
    else sp += string(pp.second / 2, pp.first);
  }
  string rsp = sp;
  reverse(all(rsp));
  cout << sp + si + rsp << '\n';
  return (0);
}
