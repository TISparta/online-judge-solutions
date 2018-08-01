#include <bits/stdc++.h>

using namespace std;

int n,memo[1000010];
const int MOD = 1000000;

int dp(int idx){
	if(!idx) return 1;
	if(memo[idx]) return memo[idx];
	return memo[idx] = ( dp(floor(idx-sqrt(idx))) + dp(floor(log(idx))) + dp(floor(idx*sin(idx)*sin(idx))) ) % MOD;
}

int main(){
	while(scanf("%d",&n),n!=-1) printf("%d\n",dp(n));
	return(0);
}
