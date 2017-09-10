#include <bits/stdc++.h>

using namespace std;

const int LEN = 100, LIM = 4000;

int n;
char line[LEN];
map < string, int > mp;

void DecimalToRoman(int num){
   map < int, string > cvt;
   cvt[1] = "I", cvt[10] = "X", cvt[100] = "C", cvt[1000] = "M";
   cvt[9] = "IX", cvt[90] = "XC", cvt[900] = "CM";
   cvt[5] = "V", cvt[50] = "L", cvt[500] = "D";
   cvt[4] = "IV", cvt[40] = "XL", cvt[400] = "CD";
   string s = "";
   for(map <int, string >:: reverse_iterator it = cvt.rbegin(); it != cvt.rend(); ++it)
      while( num >= it -> first ){
         s += ( it -> second );
         num -= it -> first;
      }
   mp[s] = n;
}

int main(){
   for( n = 0; n < LIM; n++) DecimalToRoman(n);
   while(cin.getline(line, LEN)){
      if( mp.find(line) != mp.end() ) printf("%d\n", mp[line]);
      else puts("This is not a valid number");
   }
}
