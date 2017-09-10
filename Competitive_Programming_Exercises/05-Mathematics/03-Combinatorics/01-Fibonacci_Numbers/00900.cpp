#include <bits/stdc++.h>

using namespace std;

int n;
vector <long> fib(51);

int main(){
   fib[0] = fib[1] = 1;
   for(int i = 2; i <= 50; i++)
      fib[i] = fib[i - 1] + fib[i - 2];
   while(scanf("%d", &n), n){
      printf("%ld\n", fib[n]);
   }
   return(0);
}
