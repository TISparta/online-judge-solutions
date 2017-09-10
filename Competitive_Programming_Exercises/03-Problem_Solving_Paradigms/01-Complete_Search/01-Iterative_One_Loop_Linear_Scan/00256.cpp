#include <bits/stdc++.h>

using namespace std;

int n,lim;

int main(){
   while(scanf("%d", &n) == 1){
      lim = pow(10, n / 2);
      for(int i = 0; i < lim; i++)
         for(int j = 0; j < lim; j++)
            if((i + j)*(i + j) == i * lim + j)
               printf("%.*d\n",n,i * lim + j);
   }
   return(0);
}
