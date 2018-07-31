#include <bits/stdc++.h>

#define MAX_N 110
#define MAX_W 10010
#define INF 1e5

using namespace std;

int tc,n,price,v[MAX_N],dp[MAX_W+10];

int main(){
	scanf("%d",&tc);
	while(tc--){
		fill(dp,dp+MAX_W,INF);
		scanf("%d %d",&price,&n);
		for(int i=0;i<n;i++) scanf("%d",&v[i]);
		dp[0] = 0;
		for(int i=0;i<n;i++)
			for(int j=MAX_W;j>=0;j--)
				if(j+v[i]<=MAX_W && dp[j+v[i]]>dp[j]+1)
					dp[j+v[i]] = dp[j]+1;
		while(dp[price]==INF) price++;
		printf("%d %d\n",price,dp[price]);
	}
	return(0);
}
