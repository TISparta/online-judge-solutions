#include <bits/stdc++.h>

using namespace std;

const int SIZE = 105, LEN = 30;

int n;

int ac[SIZE][LEN];
char ch[] = "IVXLC";

void DecimalToRoman(int num){
   map < int, string > cvt;
   cvt[1] = "I", cvt[10] = "X", cvt[100] = "C", cvt[1000] = "M";
   cvt[9] = "IX", cvt[90] = "XC", cvt[900] = "CM";
   cvt[5] = "V", cvt[50] = "L", cvt[500] = "D";
   cvt[4] = "IV", cvt[40] = "XL", cvt[400] = "CD";
   for(map <int, string >:: reverse_iterator it = cvt.rbegin(); it != cvt.rend(); ++it)
      while( num >= it -> first ){
         for(int j = 0; j < ( it -> second ).size(); j++)
            ac[n][ ( it -> second )[j] - 'A' ]++;
         num -= it -> first;
      }
}

void preprocess(){
   for( n = 1; n < SIZE; n++){
      DecimalToRoman(n);
      for(int j = 0; j < 5; j++){
         ac[n][ch[j] - 'A'] += ac[n - 1][ch[j] - 'A'];
      }
   }
}

int main(){
   preprocess();
   while(scanf("%d", &n), n){
      printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, ac[n]['I' - 'A'], ac[n]['V' - 'A'], ac[n]['X' - 'A'], ac[n]['L' - 'A'], ac[n]['C' - 'A']);
   }
   return(0);
}
