// Tags: Math
// Difficulty: 1.5
// Priority: 4
// Date: 09-06-2017

#include <bits/stdc++.h>

using namespace std;

string s;
long long ans;

int main(){
   cin >> s;
   ans = ( ( s[0] - '0' ) % 4 == 0 );
   for(int i = 1; i < s.size(); i++){
      int x = s[i - 1] - '0', y = s[i] - '0', z = 10 * x + y;
      if( z % 4 == 0 ) ans += i;
      if( y % 4 == 0 ) ans++;
   }
   cout << ans << endl;
   return(0);
}
