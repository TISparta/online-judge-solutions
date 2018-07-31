#include <bits/stdc++.h>

#define MAX_N 30
#define MAX_W 210

using namespace std;

int tc,W[MAX_N],dp[MAX_N][MAX_W],n,sum;
char s[200],*p;
bool ok;

int main(){
	scanf("%d\n",&tc);
	for(int t=1;t<=tc;t++){
		ok = false, n = sum = 0;
		cin.getline(s,200);
		p = strtok(s," ");
		while(p) n++, W[n] = atoi(p), sum += W[n], p = strtok(NULL," ");
		if((sum&1)==0){
			sum >>= 1;
			for(int i=0;i<=n;i++) dp[i][0] = 0;
			for(int w=0;w<=sum;w++) dp[0][w] = 0;
			for(int i=1;i<=n;i++)
				for(int w=1;w<=sum;w++)
					if(W[i]>w) dp[i][w] = dp[i-1][w];
					else dp[i][w] = max(dp[i-1][w],W[i]+dp[i-1][w-W[i]]);
			ok = (dp[n][sum]==sum);
		}
		puts( ok ? "YES" : "NO");
	}
	return(0);
}
