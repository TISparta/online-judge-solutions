#include <bits/stdc++.h>

using namespace std;

int a, b, LIS, lis[1010], path[1010], idxMax, ct;
vector < tuple <int, int, int> > v;

void printPath(int idx){
   if(path[idx] == -1){
      printf("%d\n", get<2>(v[idx]));
      return;
   }
   printPath(path[idx]);
   printf("%d\n", get<2>(v[idx]));
}

int main(){
   while(scanf("%d %d", &a, &b) != EOF) v.push_back( make_tuple(b, a, ++ct) );
   sort(v.begin(), v.end());
   reverse(v.begin(), v.end());
   for(int i = 0; i < v.size(); i++){
      path[i] = -1, lis[i] = 1;
      for(int j = 0; j < i; j++)
         if(get<1>(v[i]) > get<1>(v[j]) && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1, path[i] = j;
      if(lis[i] > LIS) LIS = lis[i], idxMax = i;  
   }
   printf("%d\n", LIS);
   printPath(idxMax);
   return(0);
}
