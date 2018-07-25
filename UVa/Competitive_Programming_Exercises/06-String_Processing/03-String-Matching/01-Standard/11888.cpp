#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int P = 31, MAX_S = 2e5 + 10;

int n;
bool pal[MAX_S], rpal[MAX_S];
string s;

void solve () {
  for (int i = 0; i + 1 < n; i++) {
    if (pal[i] and rpal[i + 1]) {
      puts("alindrome");
      return;
    }
  }
  puts(pal[n - 1] ? "palindrome" : "simple");
}

void calculate1 () {
  ll hash1 = 0LL, hash2 = 0LL, power = 1;
  for (int i = 0; i < n; i++) {
    hash1 = hash1 + power * (s[i] - 'a' + 1);
    hash2 = hash2 * P + (s[i] - 'a' + 1);
    power *= P;
    pal[i] = (hash1 == hash2);
  }
}

void calculate2 () {
  ll hash1 = 0LL, hash2 = 0LL, power = 1;
  for (int i = 0; i < n; i++) {
    hash1 = hash1 + power * (s[n - 1 - i] - 'a' + 1);
    hash2 = hash2 * P + (s[n - 1 - i] - 'a' + 1);
    power *= P;
    rpal[n - 1 - i] = (hash1 == hash2);
  }
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> s;
    n = s.size();
    calculate1();
    calculate2();
    solve();
  }
  return (0);
}
