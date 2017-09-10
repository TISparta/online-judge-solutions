#include <bits/stdc++.h>

using namespace std;

#define LIM (1L<<31)

long num, aux;
vector <int> seq;
int n, p;

int main(){
   num = aux = 1;
   while(true){
      if( num << 1 > LIM )
         break;
      while(true){
         if( aux > LIM )
            break;
         seq.push_back(aux);
         aux *= 3;
      }
      num <<= 1;
      aux = num;
   }
   sort(seq.begin(), seq.end());
   while(scanf("%d" ,&n), n){
      p = upper_bound(seq.begin(), seq.end(), n - 1) - seq.begin();
      printf("%d\n", seq[p]);
   }
   return(0);
}
