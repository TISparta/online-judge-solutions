// Tags: Constructive Algorithms
// Difficulty: 5.0
// Priority: 5
// Date: 29-07-2021

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

bool test (const string& s) {
  map <string, int> cnt;
  int n = sz(s);
  for (int i = 0; i < n; i++) {
    string z = "";
    for (int j = i; j < n; j++) {
      z += s[j];
      cnt[z] += 1;
    }
  }
  bool ok = true;
  for (auto [a, b]: cnt) ok &= (b & 1);
  return ok;
}

string solve (int n, char ch) {
  string ret = "";
  for (int bit = 10; bit >= 0; bit--) {
    if ((n >> bit) & 1) {
      int len = (1 << bit);
      string z(len, ch);
      ch += 1;
      z[max(0, len / 2 - 1)] = ch;
      ch += 1;
      ret += z;
    }
  }
  return ret;
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  /*
  int n;
  cin >> n;
  for (ll mask = 0; mask < (1LL << n); mask++) {
    string s(n, 'a');
    for (int bit = 0; bit < n; bit++) {
      if ((mask >> bit) & 1) s[bit] = 'b';
    }
    if (test(s)) {
      cout << s << endl;
      break;
    }
  }
  */
  int tt;
  cin >> tt;
  while (tt--) {
    string n;
    cin >> n;
    int len = sz(n);
    char ch = 'a';
    string ans = "";
    for (int i = 0; i < len; i++) {
      if (n[i] == '0') continue;
      string x(len, '0');
      x[i] = n[i];
      int p = stoi(x);
      if (p <= 9) {
        ans += solve(p, ch);
        break;
      }
      string z(p, ch);
      ch += 1;
      z[max(0, p / 2 - 1)] = ch;
      ch += 1;
      ans += z;
    }
    cout << ans << '\n';
    //assert(test(ans));
  }
  return (0);
}
