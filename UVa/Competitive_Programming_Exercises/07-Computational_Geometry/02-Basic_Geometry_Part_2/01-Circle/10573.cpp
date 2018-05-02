#include <bits/stdc++.h>

using namespace std;

const int LEN = 30;
const double PI = acos(-1.0);

int tc, k;
double a, b, S;
char line[LEN];

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      cin.getline(line, LEN);
      k = sscanf(line, "%lf %lf", &a, &b);
      if( k == 1 ) S = PI * a * a / 8.0;
      else S = 2.0 * PI * a * b;
      printf("%.4lf\n", S);
   }
   return(0);
}
