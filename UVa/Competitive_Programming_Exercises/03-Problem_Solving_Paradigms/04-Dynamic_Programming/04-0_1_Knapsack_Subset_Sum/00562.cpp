#include <bits/stdc++.h>

#define MAX_N 110
#define MAX_W 50010

using namespace std;

int tc,n,sum,ans,v[MAX_N],dp[MAX_N][MAX_W];

int main(){
	scanf("%d",&tc);
	while(tc--){
		sum = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&v[i]), sum += v[i];
		ans = INT_MAX;
		for(int i=0;i<=n;i++) dp[i][0] = 0;
		for(int w=0;w<=sum;w++) dp[0][w] = 0;
		for(int i=1;i<=n;i++)
			for(int w=1;w<=sum;w++){
				if(v[i]>w) dp[i][w] = dp[i-1][w];
				else dp[i][w] = max(dp[i-1][w],v[i]+dp[i-1][w-v[i]]);
				ans = min(ans,abs(sum-2*dp[i][w]));
			}
		ans = (ans == INT_MAX) ? 0 : ans;
		printf("%d\n",ans);
	}
	return(0);
}
