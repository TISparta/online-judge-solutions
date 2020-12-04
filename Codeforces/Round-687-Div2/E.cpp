// Greedy
// 4
// 29-11-2020

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
  int n, k;
  cin >> n >> k;
  vi pos;
  vi neg;
  for (int i = 0; i < n; i++) {
    int ci;
    cin >> ci;
    if (ci >= 0) pos.pb(ci);
    else neg.pb(ci);
  }
  sort(rall(pos));
  sort(all(neg));
  ll ans = 0;
  ll acc = 0;
  for (auto ci: pos) {
    ans += acc;
    acc += ci;
  }
  while (sz(neg) and acc >= 0) {
    ans += acc;
    acc += neg.back();
    neg.pop_back();
  }
  multiset <ll> st;
  st.insert(acc);
  for (int i = 0; i < k and sz(neg); i++) {
    st.emplace(neg.back());
    neg.pop_back();
  }
  while (sz(neg)) {
    auto it = --end(st);
    ll acc = *it;
    st.erase(it);
    ans += acc;
    acc += neg.back();
    neg.pop_back();
    st.emplace(acc);
  }
  cout << ans << '\n';
  return (0);
}
