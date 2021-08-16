// Tags: Greedy
// Difficulty: 3.0
// Priority: 5
// Date: 09-06-2017

#include <bits/stdc++.h>

using namespace std;

int n, k;
string s, ans;

int main(){
   cin >> n >> k;
   cin >> s;
   for(int i = 0; i < n; i++){
      int x = s[i] - 'a', y = 'z' - s[i];
      if( k == 0 ){
         ans += s[i];
         continue;
      }
      if( k - max(x, y) >= 0 ){
         k -= max(x, y);
         if( max(x, y) == x ) ans += 'a';
         else ans += 'z';
      }
      else{
         if( s[i] + k <= 'z' ) ans += ( s[i] + k ), k = 0;
         else if( s[i] - k >= 'a' ) ans += ( s[i] - k ), k = 0;
      }
   }
   if( k ) cout << -1 << endl;
   else cout << ans << endl;
   return(0);
}
