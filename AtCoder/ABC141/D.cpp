// Tags: Math
// Difficulty: 3.0
// Priority: 3
// Date: 31-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

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
  int n, m;
  cin >> n >> m;
  multiset <int> st;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    st.emplace(ai);
  }
  for (int i = 0; i < m; i++) {
    int x = *(--end(st));
    st.erase(--end(st));
    st.emplace(x / 2);
  }
  ll sum = 0;
  for (auto x: st) sum += x;
  cout << sum << '\n';
  return (0);
}
