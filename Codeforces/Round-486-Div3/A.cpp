// Implementation
// 1
// 05-11-2020

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
  map <int, int> mp;
  for (int i = 1; i <= n; i++) {
    int ai;
    cin >> ai;
    mp[ai] = i;
  }
  if (sz(mp) < k) {
    cout << "NO\n";
    return (0);
  }
  cout << "YES\n";
  auto it = begin(mp);
  for (int i = 0; i < k; i++) {
    cout << it->second << " \n"[i == k - 1];
    ++it;
  }
  return (0);
}
