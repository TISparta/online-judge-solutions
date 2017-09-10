#include <bits/stdc++.h>

#define LIMIT 105

using namespace std;

int tc, ct, carry, l1, l2, minl, maxl, k, i, j, aux;
char fibo[LIMIT][LIMIT], n1[LIMIT], n2[LIMIT], ans[LIMIT],  tmp[LIMIT], final_tmp[LIMIT], fibinary[LIMIT];
bool ok;

char* subt(char *s1, char *s2){
   l1 = strlen(s1), l2 = strlen(s2);
   carry = 0;
   for(k = 0, i = l1 - 1, j = l2 - 1; k < l2; k++, i--, j--){
      aux = (s1[i] - '0') - (s2[j] - '0') - carry;
      if(aux >= 0)
         tmp[k] = aux + '0', carry = 0;
      else
         tmp[k] = (aux + 10) + '0', carry = 1;
   }
   while(k < l1){
      aux = (s1[i--] - '0') - carry;
      if(aux >= 0)
         tmp[k++] = aux + '0', carry = 0;
      else
         tmp[k++] = aux + '0', carry = 1;
   }
   while(tmp[k - 1] == '0')
      k--;
   tmp[k] = '\0';
   i = 0;
   while(k > 0)
      final_tmp[i++] = tmp[--k];
   final_tmp[i] = '\0';
   return final_tmp;
}

bool less_or_equal(char* s1, char* s2){
   l1 = strlen(s1), l2 = strlen(s2);
   if(l1 < l2)
      return true;
   if(l1 > l2)
      return false;
   for(i = 0; i < l1; i++)
      if(s1[i] < s2[i])
         return true;
      else if(s1[i] > s2[i])
         return false;
   return true;
}

char* sum(char *s1, char *s2){
   l1 = strlen(s1), l2 = strlen(s2);
   minl = l1 > l2 ? l2 : l1;
   maxl = l1 > l2 ? l1 : l2;
   carry = 0;
   for(k = 0,i = l1 - 1,j = l2 - 1; k < minl; k++, i--, j--){
      aux = s1[i] - '0' + s2[j] - '0' + carry;
      tmp[k] = aux % 10 + '0';
      carry = aux / 10;
   }
   while(k < l1){
      aux = s1[i--] - '0' + carry;
      tmp[k++] = aux % 10 + '0';
      carry = aux / 10;
   }
   while(k < l2){
      aux = s2[j--] - '0' + carry;
      tmp[k++] = aux % 10 + '0';
      carry = aux / 10;
   }
   if(carry)
      tmp[maxl++] = carry + '0', tmp[maxl] = '0';
   else
      tmp[maxl] = '\0';
   i = 0;
   while(maxl > 0)
      final_tmp[i++] = tmp[--maxl];
   final_tmp[i] = '\0';
   return final_tmp;
}

void generateFibo(){
   fibo[0][0] = '0', fibo[0][1] = '\0';
   fibo[1][0] = '1', fibo[1][1] = '\0';
   for(int t = 2; t < LIMIT; t++)
      strcpy(fibo[t], sum(fibo[t - 1], fibo[t - 2]));
}

int main(){
   generateFibo();
   while(scanf("%s\n%s", n1, n2) == 2){
      getchar();
      if(tc)
         putchar('\n');
      tc++;
      strcpy(fibinary, fibo[0]);
      for(int x = strlen(n1) - 1, y = strlen(n1) + 1; x >= 0; x--)
         if(n1[x] == '1')
            strcpy(fibinary, sum(fibinary, fibo[y - x]));
      for(int x = strlen(n2) - 1, y = strlen(n2) + 1; x >= 0; x--)
         if(n2[x] == '1')
            strcpy(fibinary, sum(fibinary, fibo[y - x]));
      ok = false;
      ct = 0;
      for(int x = LIMIT - 1; x >= 2; x--)
         if(less_or_equal(fibo[x], fibinary))
            strcpy(fibinary, subt(fibinary, fibo[x])), ans[ct++] = '1', ok = true;
         else if(ok)
            ans[ct++] = '0';
      if(!ct)
         ans[ct++] = '0';
      ans[ct] = '\0';
      printf("%s\n", ans);
   }
   return(0);
}
