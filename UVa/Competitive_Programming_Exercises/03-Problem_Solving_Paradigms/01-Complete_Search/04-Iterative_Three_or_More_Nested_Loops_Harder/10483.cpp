#include <bits/stdc++.h>

#define SIZE 300

using namespace std;

float L, U;
long long L1, U1, c, sum, p;
vector < tuple <float, float, float, float> > v;

int main(){
   scanf("%f %f", &L, &U);
   L1 = L * 100, U1 = U * 100;
   for(long long a = 0; a < U1; a++)
      for(long long b = a; a + b < U1; b++){
         if( a * b == 10000 ) continue;
         c = round( (a + b ) / ( a * b / 10000.0 - 1 ) );
         sum = a + b + c;
         p = a * b * c;
         if( L1 <= sum and sum <= U1 and c >= b and p == 10000 * sum )
            v.push_back( make_tuple( sum / 100.0, a / 100.0, b / 100.0, c / 100.0) );
      }
   sort(v.begin(), v.end());
   for(int it = 0; it < v.size(); it++)
      printf("%.2f = %.2f + %.2f + %.2f = %.2f * %.2f * %.2f\n", get<0>(v[it]), get<1>(v[it]), get<2>(v[it]), get<3>(v[it]), get<1>(v[it]), get<2>(v[it]), get<3>(v[it]));
   return(0);
}
