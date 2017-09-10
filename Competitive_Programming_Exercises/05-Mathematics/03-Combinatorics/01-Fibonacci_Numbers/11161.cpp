#include <bits/stdc++.h>

#define LIMIT 1501
#define DIGITS 315

using namespace std;

int tc, ct, n, carry, l1, l2, minl, maxl, k, i, j, aux, t;
char fibo[LIMIT][DIGITS], lessfibo[LIMIT][DIGITS], ans[DIGITS], tmp[DIGITS], final_tmp[DIGITS], d[DIGITS];
bool ok;

char* div2(char *s1){
   l1 = strlen(s1);
   k = aux = 0;
   for(i = 0; i < l1; i++){
      aux = 10 * aux + s1[i] - '0';
      tmp[k++] = aux / 2 + '0';
      aux %= 2;
   }
   i = 0;
   for(j = 0; j < l1; j++)
      if(tmp[j] != '0'){
         i = j;
         break;
      }
   k = 0;
   for( ; i < l1; i++)
      final_tmp[k++] = tmp[i];
   final_tmp[k] = '\0';
   return final_tmp;
}

char* subt2(char *s1){
   l1 = strlen(s1);
   carry = 2;
   for(k = 0, i = l1 - 1; k < l1; k++, i--){
      aux = (s1[i] - '0') - carry;
      if(aux >= 0)
         tmp[k] = aux + '0', carry = 0;
      else
         tmp[k] = (aux + 10) + '0', carry = 1;
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

void generateFiboLessOne(){
   for(t = 1; t < LIMIT; t++){
      strcpy(lessfibo[t], sum(lessfibo[t], subt2(fibo[t])));
      strcpy(d,div2(fibo[t]));
      if((fibo[t][strlen(fibo[t]) - 1] - '0') & 1)
         strcpy(d, sum(d, fibo[1]));
      strcpy(lessfibo[t + 1], d);
   }
   lessfibo[1][0] = '0', lessfibo[1][1] = '\0';
}

void generateFibo(){
   fibo[0][0] = '1', fibo[0][1] = '\0';
   fibo[1][0] = '1', fibo[1][1] = '\0';
   for(t = 2; t < LIMIT; t++)
      strcpy(fibo[t], sum(fibo[t - 1], fibo[t - 2]));
}

int main(){
   generateFibo();
   generateFiboLessOne();
   while(scanf("%d", &n), n)
      printf("Set %d:\n%s\n", ++tc, lessfibo[n]);
   return(0);
}
