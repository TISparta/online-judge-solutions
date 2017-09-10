#include <bits/stdc++.h>

using namespace std;

struct Polynomial{
   int degree;
   vector < long long > coef;
   Polynomial() {};
   Polynomial(int degree_): degree(degree_){
      coef.assign(degree + 1, 0);
   };
   Polynomial operator * (const Polynomial& other) const{
      Polynomial r(degree + other.degree);
      for(int i = 0; i <= degree; i++)
         for(int j = 0; j <= other.degree; j++)
            r.coef[i + j] += coef[i] * other.coef[j];
      return r;
   }
}p, q;

void print(Polynomial& p){
   for(int it = p.degree; it >= 0; it--){
      if( it and it != p.degree and p.coef[it] != 0 ){
         putchar(' ');
         if( p.coef[it] > 0 ) putchar('+');
         else if( p.coef[it] < 0 ) putchar('-');
         putchar(' ');
      }
      if( it and p.coef[it] != 0 ){
         if( abs(p.coef[it]) != 1 ) printf("%lld", abs(p.coef[it]));
         if( it != 1 ) printf("x^%d", it);
         else putchar('x');
      }
      else if( it == 0 ){
         putchar(' ');
         if( p.coef[it] >= 0 ) putchar('+');
         else putchar('-');
         putchar(' ');
         printf("%lld", abs(p.coef[it]));
      }
   }
   printf(" = 0\n");
}

int n, root;

int main(){
   while(~scanf("%d", &n)){
      scanf("%d", &root);
      p = Polynomial(1);
      p.coef[0] = -root, p.coef[1] = 1;
      for(int it = 1; it < n; it++){
         scanf("%d", &root);
         q = Polynomial(1);
         q.coef[0] = -root, q.coef[1] = 1;
         p = p * q;
      }
      print(p);
   }
   return(0);
}
