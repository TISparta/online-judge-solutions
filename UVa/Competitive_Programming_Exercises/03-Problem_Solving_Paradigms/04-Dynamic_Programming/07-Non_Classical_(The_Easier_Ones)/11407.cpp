#include <bits/stdc++.h>

#define MAX_N 10010

using namespace std;

int tc,n,memo[MAX_N];

int dp(int sum){
	if(sum==0) return 0;
	if(memo[sum]) return memo[sum];
	int ans = INT_MAX;
	for(int it=1;it*it<=sum;it++)
		ans = min(ans,1+dp(sum-it*it));
	return memo[sum] = ans;
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		printf("%d\n",dp(n));
	}
	return(0);
}
