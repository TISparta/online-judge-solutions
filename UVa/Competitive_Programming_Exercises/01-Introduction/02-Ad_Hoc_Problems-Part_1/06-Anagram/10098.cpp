#include <bits/stdc++.h>

#define SIZE 20

using namespace std;

int tc, len;
char s[SIZE];

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      scanf("%s", s);
      len = strlen(s);
      sort(s, s + len);
      do{
         printf("%s\n", s);
      }while(next_permutation(s, s + len));
      putchar('\n');
   }
   return(0);
}
