#include <bits/stdc++.h>

using namespace std;

struct Polynomial{
   int degree;
   vector < long long > coef;
   Polynomial() {};
   Polynomial(int degree_): degree(degree_){
      coef.assign(degree + 1, 0);
   };
}p;

int n, k;

void print(Polynomial& x){
   if( x.degree == -1 ) puts("0");
   for(int it = 0; it <= x.degree; it++)
      printf( it == x.degree ? "%lld\n" : "%lld ", x.coef[it]);
}

int main(){
   while(scanf("%d %d", &n, &k), ~n and ~k){
      p = Polynomial(n);
      for(int it = 0; it <= n; it++) scanf("%lld", &p.coef[it]);
      while( p.degree >= k ) p.coef[p.degree - k] -= p.coef[p.degree], p.degree--;
      print(p);
   }
   return(0);
}
