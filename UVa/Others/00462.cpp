/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags : Implementation
 * > Difficulty : 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int total_score, mx_cards;
map <char, vector <char>> suit;

int getDec (const vector <char>& arr) {
  int ret = 0;
  if (arr.size() == 1 and arr[0] == 'K') ret += 1;
  if (arr.size() <= 2 and find(begin(arr), end(arr), 'Q') != end(arr)) ret += 1;
  if (arr.size() <= 3 and find(begin(arr), end(arr), 'J') != end(arr)) ret += 1;
  return ret;
}

int getInc (const vector <char>& arr) {
  if (arr.size() == 2) return 1;
  if (arr.size() <= 1) return 2;
  return 0;
}

bool isStopped (const vector <char>& arr) {
  if (find(begin(arr), end(arr), 'A') != end(arr)) return true;
  if (arr.size() >= 2 and find(begin(arr), end(arr), 'K') != end(arr)) return true;
  if (arr.size() >= 3 and find(begin(arr), end(arr), 'Q') != end(arr)) return true;
  return false;
}

void solve () {
  int inc = 0, dec = 0, stopped = 0;
  for (char ch: {'S', 'H', 'D', 'C'}) {
    dec += getDec(suit[ch]);
    inc += getInc(suit[ch]);
    stopped += isStopped(suit[ch]);
  }
  total_score -= dec;
  if (total_score >= 16 and stopped == 4) {
    puts("BID NO-TRUMP");
    return;
  }
  total_score += inc;
  if (total_score < 14) {
    puts("PASS");
    return;
  }
  for (char ch: {'S', 'H', 'D', 'C'}) {
    if (suit[ch].size() == mx_cards) {
      printf("BID %c\n", ch);
      return;
    }
  }
}

int valueOf (char ch) {
  if (ch == 'J') return 1;
  if (ch == 'Q') return 2;
  if (ch == 'K') return 3;
  if (ch == 'A') return 4;
  return 0;
}

bool read () {
  string line;
  if (not getline(cin, line)) return false;
  istringstream ss(line);
  string s;
  while (ss >> s) {
    total_score += valueOf(s[0]);
    suit[s[1]].push_back(s[0]);
    mx_cards = max(mx_cards, (int) suit[s[1]].size());
  }
  return true;
}

void clear () {
  mx_cards = 0;
  total_score = 0;
  suit.clear();
}

int main () {
  while (read()) {
    solve();
    clear();
  }
  return (0);
}
