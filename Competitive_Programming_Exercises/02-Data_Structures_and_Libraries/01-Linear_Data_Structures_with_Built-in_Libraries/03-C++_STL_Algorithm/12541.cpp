#include <bits/stdc++.h>

#define SIZE 20

using namespace std;

int n, dd, mm, yy;
char s[SIZE];
vector < tuple <int, int, int, string> > v;

int main(){
   scanf("%d\n", &n);
   for(int i = 0; i < n; i++){
      scanf("%s %d %d %d", s, &dd, &mm, &yy);
      v.push_back( make_tuple(yy, mm, dd, string(s)) );
   }
   sort(v.begin(), v.end());
   printf("%s\n", (get<3>(v.back())).c_str());
   printf("%s\n", (get<3>(v[0])).c_str());
   return(0);
}
