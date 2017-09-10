#include <bits/stdc++.h>

const long long  LIM = 2*(int)1e8;

using namespace std;

bitset<LIM>prime;
vector<int>p;
vector<pair<int,int>>twin_prime;
int n;

void sieve(){
	p.push_back(2);
	for(int i=3;i<=LIM;i+=2){
		if(!prime[i]){
			for(long long j=(long long)i*i;j<=LIM;j+=2*i)
				prime[j] = 1;
			if(i-p.back()==2)
				twin_prime.push_back(make_pair(p.back(),i));
			p.push_back(i);
		}
	}
}

int main(){
	sieve();
	while(scanf("%d",&n)==1)
		printf("(%d, %d)\n",twin_prime[n-1].first,twin_prime[n-1].second);
	return(0);
}
