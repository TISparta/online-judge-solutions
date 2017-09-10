#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int n, num, pos, lis, idxMax;
vector <int> v, u, path, idx;

void printPath(int idx){
   if(path[idx] == -1){
      printf("%d\n", v[idx]);
      return;
   }
   printPath(path[idx]);
   printf("%d\n", v[idx]);
}

int main(){
   while(scanf("%d",&num) != EOF) v.pb(num);
   n = v.size();
   u.resize(n), idx.resize(n), path.resize(n, -1);
   for(int i = 0; i < n; i++){
      pos = lower_bound(u.begin(), u.begin() + lis, v[i]) - u.begin();
      u[pos] = v[i];
      idx[pos] = i;
      path[i] = pos ? idx[pos - 1] : -1;
      if(pos + 1 > lis) lis = pos + 1, idxMax = i;
   }
   printf("%d\n", lis);
   puts("-");
   printPath(idxMax);
   return(0);
}
