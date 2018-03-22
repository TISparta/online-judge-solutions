#include <bits/stdc++.h>

using namespace std;

int d, e, f;
char s[15];
bool number[10], ok;

bool isValid(int a, int b, int c){
   d = 5 - c, e = 5 - b, f = 5 - a;
   memset(number, false, sizeof number);
   number[a] = true, number[b] = true;
   number[c] = true, number[d] = true;
   number[e] = true, number[f] = true;
   for(int i = 0; i <= 5; i++)
      if(!number[i]) return false;
   if(s[6] != s[a] || s[7] != s[b] ||
      s[8] != s[c] || s[9] != s[d] ||
      s[10] != s[e] || s[11] != s[f])
      return false;
   return true;
}

int main(){
   while(scanf("%s",s)==1){
      ok = false;
      for(int a = 0; a <= 5; a++)
         for(int b = 0; b <= 5; b++)
            for(int c = 0; c <= 5; c++)
               if(isValid(a, b, c))
                  ok = true;
      puts(ok ? "TRUE" : "FALSE");
   }
   return(0);
}
