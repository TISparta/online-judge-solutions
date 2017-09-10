#include <bits/stdc++.h>

using namespace std;

int tc, n, t;
vector <long> fib;

int main(){
   fib.push_back(1);
   fib.push_back(2);
   for(int i = 2; i <= 50; i++)
      fib.push_back(fib[i - 1] + fib[i - 2]);
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &n);
      printf("Scenario #%d:\n%ld\n\n", ++t, fib[n]);
   }

   return(0);
}
