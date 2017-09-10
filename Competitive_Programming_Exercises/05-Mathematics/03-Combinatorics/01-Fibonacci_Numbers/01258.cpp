#include <bits/stdc++.h>

#define LIM 91

using namespace std;

int main(){
   vector <long long> fib;
   long long n;
   vector < pair<int, long long> > x;
   fib.push_back(1), fib.push_back(1);
   for(int i = 2; i < LIM; i++)
      fib.push_back(fib[i - 1] + fib[i - 2]);
   while(scanf("%lld", &n) == 1){
      printf("%lld\n", n);
      for(int i = LIM - 1; n != 0; i--){
         if(fib[i] <= n)
            x.push_back( make_pair(i, fib[i])),
            n -= fib[i];
      }
      for(int i = 0; i < x.size(); i++)
         printf("%d ", x[i].first);
      putchar('\n');
      for(int i = 0; i < x.size(); i++)
         printf("%lld ", x[i].second);
      putchar('\n');
      putchar('\n');
      x.clear();
   }
   return(0);
}
