#include <bits/stdc++.h>

using namespace std;

long long n, ct, w[1000], pib;
char s[1000];
bool ok;

void reset(){
   for(int i = 0; i < n; i++)
      w[i] = 0;
   n = 0, ct = 1;
}

int main(){
   while(cin.getline(s, 1000)){
      reset();
      for(int i = strlen(s) - 1; i >= 0; i--){
         if(s[i] == ' '){
            n++, ct = 1;
            while(s[i] == ' ') i--;
            i++;
            continue;
         }
         w[n] += (s[i] - 'a' + 1) * ct;
         ct <<= 5;
      }
      n++;
      for(long long C = 1; ; C++){
         ok = true, pib = 1;
         for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
               if(i != j && (C / w[i]) % n == (C / w[j]) % n)
                  ok = false, pib = max(pib, min((C / w[i] + 1) * w[i], (C / w[j] + 1) * w[j]));
         if(ok){
            printf("%s\n", s);
            printf("%lld\n\n", C);
            break;
         }
         C = pib - 1;
      }
   }
   return(0);
}
