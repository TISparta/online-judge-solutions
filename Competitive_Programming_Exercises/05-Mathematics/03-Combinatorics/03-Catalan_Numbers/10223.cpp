#include <bits/stdc++.h>

#define LIM 20

using namespace std;

int main(){
	long long N,catalan_number[LIM];
	double ans;
	for(int n=1;n<LIM;n++){
		ans = 1;
		for(int k=2;k<=n;k++)
			ans *= (n+k);
		for(int k=2;k<=n;k++)
			ans /= k;
		catalan_number[n]= ceil(ans);
	}
	catalan_number[17]--;
	catalan_number[19]--;
	while(scanf("%lld",&N)==1){
		for(int i=1;i<LIM;i++)
			if(catalan_number[i]==N){
				printf("%d\n",i);
				break;
			}
	}
	return(0);
}
