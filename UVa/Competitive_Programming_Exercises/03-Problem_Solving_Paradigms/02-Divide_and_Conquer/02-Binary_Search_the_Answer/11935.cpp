#include <bits/stdc++.h>

using namespace std;

int main(){
   char s[100], c1[100], c2[100];
   float k, ans, ln, cn, l, c, lpos, cpos; 
   while(cin.getline(s, 100)){
      l = lpos = ln = ans = c = 0;
      k = sscanf(s, "%f %s %s %f", &cpos, c1, c2, &ln);
      if(cpos == 0 && ln == 0)
         break;
      lpos = cpos;
      cn = ln;
      while(true){
         c += l * (cpos - lpos) + ln * (cpos - lpos) / 100;
         ans = max(ans, c);
         lpos = cpos;
         if(k == 4)
            ln = cn;
         if(c1[0] == 'L')
            l++;
         else if(c1[1] == 'a')
            c = 0;
         else if(c1[0] == 'M')
            l = 0;
         else if(c1[1] == 'o')
            break;
         cin.getline(s, 100);
         k = sscanf(s, "%f %s %s %f", &cpos, c1, c2, &cn);
      }
      printf("%.3f\n", ans);
   }
   return(0);
}
