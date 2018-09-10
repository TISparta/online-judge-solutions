/**
 * > Author : TISparta
 * > Date : 09-09-18
 * > Tags : Implementation
 * > Difficulty : 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int s;
  cin >> s;
  if (s <= 90) printf("%d %s\n", 0, "No punishment");
  else if (s <= 110) printf("%d %s\n", (s - 90) * 300, "Warning");
  else printf("%d %s\n", (s - 90) * 500, "License removed");
  return (0);
}
