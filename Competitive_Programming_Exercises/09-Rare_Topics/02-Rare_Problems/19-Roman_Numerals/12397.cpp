#include <bits/stdc++.h>

using namespace std;

int n;

int numberOfMatches(int num){
   map < int, int > cvt;
   cvt[1] = 1, cvt[10] = 2, cvt[100] = 2, cvt[1000] = 4;
   cvt[9] = 3, cvt[90] = 4, cvt[900] = 6;
   cvt[5] = 2, cvt[50] = 2, cvt[500] = 3;
   cvt[4] = 3, cvt[40] = 4, cvt[400] = 5;
   int matches = 0;
   for(map <int, int >:: reverse_iterator it = cvt.rbegin(); it != cvt.rend(); ++it)
      while( num >= it -> first ){
         matches += it -> second;
         num -= it -> first;
      }
   return matches;
}

int main(){
   while(~scanf("%d", &n)) printf("%d\n", numberOfMatches(n));
   return(0);
}
