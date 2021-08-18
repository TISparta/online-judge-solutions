// Tags: Greedy
// Difficulty: 2.0
// Priority: 1
// Date: 26-07-2016

#include <bits/stdc++.h>

using namespace std;

long long fib[100],cumSum;
int s,k,lim;
vector<int>ans;

int main(){
	scanf("%d %d",&s,&k);
	fib[0] = fib[1] = 1, cumSum = 2;
	for(int i=2;i<90;i++){
		if(i>k) cumSum -= fib[i-k-1];
		fib[i] = cumSum;
		cumSum += fib[i];
		if(fib[i]>(int)1e15){
			lim = i;
			break;
		}
	}
	ans.push_back(0);
	while(s){
		for(int i=0;i<lim;i++){
			if(s<fib[i]){
				s -= fib[i-1];
				ans.push_back(fib[i-1]);
				break;
			}
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++)
		printf(i!=ans.size()-1 ? "%d " : "%d\n", ans[i]);
	return(0);
}
