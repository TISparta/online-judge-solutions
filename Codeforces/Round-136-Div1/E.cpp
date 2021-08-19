// Tags: BIT, Two Pointers
// Difficulty: 8.0
// Priority: 3
// Date: 21-06-2017

#include <bits/stdc++.h>

#define LSOne(B) ( B & -B )

using namespace std;

typedef long long ll;

const int MAX_A = 1e9 + 10, MAX_N = 1e5 + 10;

struct BIT{
   vector <int> ft;
   BIT(int N_){
      ft.resize(N_+ 1, 0);
   }
   void update(int idx, const int& val){
      while( idx < ft.size() ){
         ft[idx] += val;
         idx += LSOne(idx);
      }
   }

   int get(int idx){
      int sum = 0;
      while( idx ){
         sum += ft[idx];
         idx -= LSOne(idx);
      }
      return sum;
   }
};

int n, a[MAX_N], l, r, ct = 1;
ll k, ans, inv, sum;
set <int> st;
map <int, int> mp;

int main(){
   cin >> n >> k;
   for(int i = 1; i <= n; i++) scanf("%d", a + i), st.insert(a[i]);
   for(set <int> :: iterator it = st.begin(); it != st.end(); ++it) mp[*it] = ct++;
   for(int i = 1; i <= n; i++) a[i] = mp[a[i]];
   BIT ft1(ct), ft2(ct);
   l = 1, r = n + 1;
   ft1.update(a[1], 1);
   while( l + 1 != r ){
      sum = ( a[r - 1] < a[1] );
      sum += ft2.get( a[r - 1] - 1 );
      if( inv + sum > k ) break;
      ft2.update(a[--r], 1);
      inv += sum;
   }
   if( r == n + 1 ){
      cout << 0 << endl;
      return(0);
   }
   if( l + 1 == r ){
      cout << 1LL * n * ( n - 1 ) / 2 << endl;
      return(0);
   }
   ans = n - r + 1;
   int pib = r;
   while( l <= pib and l < n ){
      l++;
      inv += ft1.get( ct ) - ft1.get( a[l] );
      inv += ft2.get( a[l] - 1 );
      ft1.update(a[l], 1);
      if( inv <= k ){
         ans += n - r + 1;
      }
      else{
         while( r < n ){
            inv -= ft1.get( ct ) - ft1.get( a[r] );
            inv -= ft2.get( a[r] - 1 );
            ft2.update(a[r], -1);
            r++;
            if( inv <= k ) break;
         }
         if( inv <= k ){
            ans += n - r + 1;
         }
      }
   }
   cout << ans << endl;
   return(0);
}
