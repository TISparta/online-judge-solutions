// Tags: Implementation
// Difficulty: 4.0
// Priority: 1
// Date: 31-10-2020

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

string convert_to_Roman (ll x) {
  assert(x <= 3000);
  if (x == 0) return "";
  if (x < 4) return string(x, 'I');
  if (x == 4) return "IV";
  if (x < 9) return "V" + string(x - 5, 'I');
  if (x == 9) return "IX";
  if (x == 10 or x == 20 or x == 30) return string(x / 10, 'X');
  if (x == 40) return "XL";
  if (x == 50 or x == 60 or x == 70 or x == 80) return "L" + string(x / 10 - 5, 'X');
  if (x == 90) return "XC";
  if (x < 100) return convert_to_Roman((x / 10) * 10) + convert_to_Roman(x % 10);
  if (x == 100 or x == 200 or x == 300) return string(x / 100, 'C');
  if (x == 400) return "CD";
  if (x == 500 or x == 600 or x == 700 or x == 800) return "D" + string(x / 100 - 5, 'C');
  if (x == 900) return "CM";
  if (x < 1000) return convert_to_Roman((x / 100) * 100) + convert_to_Roman(x % 100);
  if (x == 1000 or x == 2000 or x == 3000) return string(x / 1000, 'M');
  return convert_to_Roman((x / 1000) * 1000) + convert_to_Roman(x % 1000);
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  string a, b, c;
  cin >> a >> b >> c;
  ll x = 0;
  ll p = 1;
  reverse(all(c));
  for (char ch: c) {
    int val = ('0' <= ch and ch <= '9') ? (ch - '0') : 10 + (ch - 'A');
    x = x + val * p;
    p *= stoi(a);
    assert(x >= 0);
  }
  assert(x <= 1e15);
  if (b[0] != 'R') {
    string ans = (x == 0) ? "0" : "";
    while (x) {
      int d = x % stoi(b);
      x /= stoi(b);
      if (d <= 9) ans += char('0' + d);
      else ans += char('A' + d - 10);
    }
    reverse(all(ans));
    cout << ans << '\n';
    return (0);
  }
  cout << convert_to_Roman(x) << '\n';
  return (0);
}
