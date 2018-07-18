/**
 * > Author: TISparta
 * > Date: 02-07-18
 * > Tags: Ad-Hoc
 * > Difficulty: 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int hh, mm, ss;
  char xm[5];
  scanf("%2d:%2d:%2d%s", &hh, &mm, &ss, &xm);
  if (hh == 12 and xm[0] == 'A') hh = 0;
  else if (hh != 12 and xm[0] == 'P') hh += 12;
  printf("%.2d:%.2d:%.2d\n", hh, mm, ss);
  return (0);
}
