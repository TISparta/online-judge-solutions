#include <bits/stdc++.h>

using namespace std;

int n;

long long gcd(long long a, long long b){
   return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b){
   return a * ( b / gcd(a, b));
}

int cardinality(int num){
	int ct = 1, i;
	vector<int> div;
	for(i = 1; i * i < num; i++)
		if(num % i == 0) div.push_back(i), div.push_back(n/i);
	if(i * i == num) div.push_back(i);
	for(int i = 0; i < div.size(); i++)
		for(int j = i + 1; j < div.size(); j++)
			if( lcm(div[i], div[j]) == n) ct++;
	return ct;
}

int main(){
	while(scanf("%d",&n),n) printf("%d %d\n",n,cardinality(n));
	return(0);
}
