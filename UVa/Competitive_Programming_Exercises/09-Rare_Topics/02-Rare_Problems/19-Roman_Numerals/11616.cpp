#include <bits/stdc++.h>

using namespace std;

const int LEN = 50;

char line[LEN];

void DecimalToRoman(int num){
   map < int, string > cvt;
   cvt[1] = "I", cvt[10] = "X", cvt[100] = "C", cvt[1000] = "M";
   cvt[9] = "IX", cvt[90] = "XC", cvt[900] = "CM";
   cvt[5] = "V", cvt[50] = "L", cvt[500] = "D";
   cvt[4] = "IV", cvt[40] = "XL", cvt[400] = "CD";
   for(map <int, string >:: reverse_iterator it = cvt.rbegin(); it != cvt.rend(); ++it)
      while( num >= it -> first ){
         printf("%s", ( it -> second ).c_str());
         num -= it -> first;
      }
   putchar('\n');
}

void RomanToDecimal(char R[]){
   map < char, int > cvt;
   cvt['I'] = 1, cvt['V'] = 5, cvt['X'] = 10, cvt['L'] = 50;
   cvt['C'] = 100, cvt['D'] = 500, cvt['M'] = 1000;
   int num = 0;
   for(int it = 0; R[it]; it++)
      if( R[it + 1] and cvt[R[it]] < cvt[R[it + 1]] )
         num += cvt[R[it + 1]] - cvt[R[it]], it++;
      else
         num += cvt[R[it]];
   printf("%d\n", num);
}

int main(){
   while(~scanf("%s", line)){
      if( isdigit(line[0]) ) DecimalToRoman( atoi(line) );
      else RomanToDecimal(line);
   }
   return(0);
}
