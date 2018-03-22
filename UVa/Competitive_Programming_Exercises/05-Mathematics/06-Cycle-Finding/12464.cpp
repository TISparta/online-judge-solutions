#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int pos, mu, lambda;
long long alfa, beta, n;
double next_;
vector <double> dp;

bool check(){
   for(int i = 1; i < dp.size(); i++)
      if( fabs(dp[i] - next_) < EPS and fabs(dp[i - 1] - dp.back()) < EPS ){
         mu = i - 1;
         lambda = pos - mu - 1;
         return true;
      }
   return false;
}

int main(){
   while(scanf("%lld %lld %lld", &alfa, &beta, &n), alfa | beta | n){
      dp.clear();
      dp.push_back(alfa);
      dp.push_back(beta);
      pos = 2;
      while( true ){
         next_ = ( 1.0 + dp[pos - 1] ) / dp[ pos - 2];
         if( check() ) break;
         dp.push_back(next_);
         pos++;
      }
      if( n < mu ) pos = n;
      else pos = mu + ( n - mu ) % lambda;
      printf("%lld\n", (long long)round(dp[pos]));
   }
   return(0);
}
