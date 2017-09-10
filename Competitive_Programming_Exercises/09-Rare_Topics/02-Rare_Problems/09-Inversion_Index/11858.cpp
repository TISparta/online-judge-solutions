#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1000005;

int n, v[SIZE];

long long Merge(int lo, int mid, int hi){
   long long inv = 0;
   vector <int> L, R;
   int l1 = mid - lo + 1, l2 = hi - mid;
   for(int it = 0; it < l1; it++) L.push_back(v[lo + it]);
   for(int it = 0; it < l2; it++) R.push_back(v[mid + 1 + it]);
   L.push_back(INT_MAX), R.push_back(INT_MAX);
   int i = 0, j = 0;
   for(int it = lo; it <= hi; it++)
      if( L[i] <= R[j] )
         v[it] = L[i++];
      else
         v[it] = R[j++], inv += l1 - i;
   return inv;
}

long long MergeSort(int lo, int hi){
   long long inv = 0;
   if( lo < hi ){
      int mid = ( lo + hi ) / 2;
      inv += MergeSort(lo, mid);
      inv += MergeSort(mid + 1, hi);
      inv += Merge(lo, mid, hi);
   }
   return inv;
}

int main(){
   while(~scanf("%d", &n)){
      for(int it = 0; it < n; it++)
         scanf("%d", v + it);
      printf("%lld\n", MergeSort(0, n - 1));
   }
   return(0);
}
