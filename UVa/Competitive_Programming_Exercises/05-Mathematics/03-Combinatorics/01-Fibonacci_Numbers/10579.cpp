#include <bits/stdc++.h>

#define LIMIT 5001
#define MAX 1050

using namespace std;

int n, l1, l2, minl, maxl, aux, carry, i, j, k;
char fibo[LIMIT][MAX], tmp[MAX], final_tmp[MAX];

char* sum(char *s1, char *s2){
   l1 = strlen(s1), l2 = strlen(s2);
   minl = l1 > l2 ? l2 : l1;
   maxl = l1 > l2 ? l1 : l2;
   carry = 0;
   for(k = 0, i = l1 - 1, j = l2 - 1; k < minl; k++, i--, j--){
      aux = s1[i] - '0' + s2[j] - '0' + carry;
      tmp[k] = aux % 10 + '0';
      carry = aux / 10;
   }
   while(k < l1){
      aux = s1[i] - '0' + carry;
      tmp[k] = aux % 10+  '0';
      carry = aux / 10;
      k++, i--;
   }
   if(carry)
      tmp[maxl++] = carry + '0', tmp[maxl] = '\0';
   else
      tmp[maxl] = '\0';
   i = 0;
   while(final_tmp[i++] = tmp[--maxl]) ;
   final_tmp[i] = '\0';
   return final_tmp;
}

void generateFibo(){
   fibo[0][0] = '0', fibo[0][1] = '\0';
   fibo[1][0] = '1', fibo[0][1] = '\0';
   for(int i = 2; i <= LIMIT; i++)
      strcpy(fibo[i],sum(fibo[i - 1], fibo[i - 2]));
}

int main(){
   generateFibo();
   while(scanf("%d",&n) == 1)
      printf("%s\n", fibo[n]);
   return(0);
}
