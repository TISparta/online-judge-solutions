// Math
// 4
// 09-09-2020

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
  int n;
  cin >> n;
  vi t(n);
  for (int& ti: t) cin >> ti;
  sort(all(t));
  // t1 <= t2 <= ... <= tn
  // Case 1: 2tn >= t1 + t2 + ... + tn-1
  //  First person: n->1:n-1
  //  Second person: 1:n
  //  Ans: 2tn
  // Case 2: 2tn < t1 + t2 + ... + tn-1
  //  First person: n->1:n-1
  //  Second person: 1:n
  //  ans: sum
  ll sum = accumulate(all(t), 0LL);
  if (sum - t[n - 1] <= 2 * t[n - 1]) cout << 2 * t[n - 1] << '\n';
  else cout << sum << '\n';
  return (0);
}
