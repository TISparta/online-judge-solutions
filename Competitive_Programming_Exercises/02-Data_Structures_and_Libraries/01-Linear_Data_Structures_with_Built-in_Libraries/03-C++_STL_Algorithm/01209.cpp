#include <bits/stdc++.h>

using namespace std;

int _max;
string s, ss, ans;
vector <string> v;

int distance(string x){
   int a, b, aux = INT_MAX;
   for(int i = 1; i < x.size(); i++){
      a = x[i] - 'A', b = x[i-1] - 'A';
      aux = min(aux, abs(a - b));
   }
   return aux;
}

int main(){
   while(cin >> s){
      ans = "", v.clear(), ss = s, _max = -1;
      for(int i = 0; i < 10; i++){
         prev_permutation(ss.begin(), ss.end());
         v.push_back(ss);
      }
      v.push_back(s);
      for(int i = 0; i < 10; i++){
         next_permutation(s.begin(), s.end());
         v.push_back(s);
      }
      sort(v.begin(), v.end());
      for(int i = 0; i < v.size(); i++){
         int p = distance(v[i]);
         if(p > _max) _max = p, ans = v[i] + to_string(p);
      }
      cout << ans << endl;
   }
   return(0);
}
