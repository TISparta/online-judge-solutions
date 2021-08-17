// Tags: Implementation
// Difficulty: 1.7
// Priorioty: 4
// Date: 16-08-2021

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
  vi months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string s1, s2;
  cin >> s1 >> s2;
  if (s1 > s2) swap(s1, s2);
  auto get = [&] (string s) {
    int year = stoi(s.substr(0, 4));
    int month = stoi(s.substr(5, 2));
    int day = stoi(s.substr(8, 2));
    return mt(year, month, day);
  };
  auto [year1, month1, day1] = get(s1);
  auto [year2, month2, day2] = get(s2);
  auto fix_if_leap = [&] (int year) {
    months[1] = 28;
    if (year % 400 == 0 or (year % 100 and year % 4 == 0)) months[1] = 29;
  };
  int ans = 0;
  while (mt(year1, month1, day1) != mt(year2, month2, day2)) {
    ans += 1;
    fix_if_leap(year1);
    day1 += 1;
    if (day1 == months[month1 - 1] + 1) {
      day1 = 1;
      month1 += 1;
    }
    if (month1 == 13) {
      month1 = 1;
      year1 += 1;
    }
  }
  cout << ans << '\n';
  return (0);
}
