// Greedy
// 2
// 16-01-2021

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
  int k;
  cin >> s >> k;
  map <char, int> cnt;
  for (char ch: s) cnt[ch] += 1;
  vector <pair <int, char>> arr;
  for (auto [ch, z]: cnt) arr.emplace_back(z, ch);
  sort(all(arr));
  set <char> pop;
  for (auto [z, ch]: arr) {
    if (z > k) break;
    k -= z;
    pop.emplace(ch);
  }
  string ans = "";
  for (char ch: s) if (pop.count(ch) == 0) ans += ch;
  cout << sz(set <char> {all(ans)}) << '\n';
  cout << ans << '\n';
  return (0);
}
