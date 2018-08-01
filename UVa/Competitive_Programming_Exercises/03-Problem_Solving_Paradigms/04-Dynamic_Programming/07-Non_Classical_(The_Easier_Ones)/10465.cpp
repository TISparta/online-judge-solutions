#include <bits/stdc++.h>

using namespace std;

int m,n,t,dp[10010];

int main(){
	while(scanf("%d %d %d",&m,&n,&t)==3){
		memset(dp,-1,sizeof dp);
		dp[0] = 0;
		for(int it=1;it<=t;it++){
			if(it>=m && ~dp[it-m]) dp[it] = dp[it] = 1+dp[it-m];
			if(it>=n && ~dp[it-n]) dp[it] = max(dp[it],1+dp[it-n]);
		}
		if(~dp[t]) printf("%d\n",dp[t]);
		else{
			for(int it=t-1;it>=0;it--)
				if(~dp[it]) printf("%d %d\n",dp[it],t-it), it = 0;
		}
	}
	return(0);
}
